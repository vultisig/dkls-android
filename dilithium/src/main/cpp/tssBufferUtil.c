/*
 * JNI helper for setting/getting bytes on a SWIG-wrapped tss_buffer.
 *
 * IMPORTANT: The JNI function names below encode your Java package name.
 * Update "com_example_yourapp_mldsa" to match your actual package.
 *
 * JNI naming convention: Java_<package>_<Class>_<method>
 *   - Replace dots with underscores in the package name.
 *   - Example: package "com.mycompany.app.mldsa" becomes "com_mycompany_app_mldsa"
 */

#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "vs-core.h"

JNIEXPORT void JNICALL
Java_com_silencelaboratories_godilithium_TssBufferUtilJNI_set_1bytes_1on_1tss_1buffer(JNIEnv *env,
                                                                            jobject obj,
                                                                            jobject jarg1,
                                                                            jbyteArray jarg1_) {
    jsize byteArrayLen = (*env)->GetArrayLength(env, jarg1_);
    jbyte *nativeBytes = (*env)->GetByteArrayElements(env, jarg1_, 0);

    uint8_t *nativeMemory = (uint8_t *) malloc(byteArrayLen);
    if (nativeMemory == NULL) {
        (*env)->ReleaseByteArrayElements(env, jarg1_, nativeBytes, 0);
        return;
    }
    memcpy(nativeMemory, nativeBytes, byteArrayLen);

    jclass tssBufferClass = (*env)->GetObjectClass(env, jarg1);
    jfieldID ptrField = (*env)->GetFieldID(env, tssBufferClass, "swigCPtr", "J");
    jlong swigCPtr = (*env)->GetLongField(env, jarg1, ptrField);

    tss_buffer *buffer = (tss_buffer *) (intptr_t) swigCPtr;
    buffer->ptr = nativeMemory;
    buffer->len = (uintptr_t) byteArrayLen;

    (*env)->ReleaseByteArrayElements(env, jarg1_, nativeBytes, 0);
}

JNIEXPORT jbyteArray JNICALL
Java_com_silencelaboratories_godilithium_TssBufferUtilJNI_get_1bytes_1from_1tss_1buffer(
        JNIEnv *env, jobject obj, jobject jarg1) {
    jclass tssBufferClass = (*env)->GetObjectClass(env, jarg1);
    jfieldID ptrField = (*env)->GetFieldID(env, tssBufferClass, "swigCPtr", "J");
    jlong swigCPtr = (*env)->GetLongField(env, jarg1, ptrField);

    tss_buffer *buffer = (tss_buffer *) (intptr_t) swigCPtr;

    jsize len = (jsize) buffer->len;
    jbyteArray byteArray = (*env)->NewByteArray(env, len);
    if (byteArray == NULL) {
        return NULL;
    }

    (*env)->SetByteArrayRegion(env, byteArray, 0, len, (const jbyte *) buffer->ptr);
    return byteArray;
}