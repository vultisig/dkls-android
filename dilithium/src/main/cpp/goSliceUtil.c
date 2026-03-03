/*
 * JNI helper for setting/getting bytes on a SWIG-wrapped go_slice.
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
Java_com_silencelaboratories_godilithium_GoSliceUtilJNI_set_1bytes_1on_1go_1slice(JNIEnv *env,
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

    jclass goSliceClass = (*env)->GetObjectClass(env, jarg1);
    jfieldID ptrField = (*env)->GetFieldID(env, goSliceClass, "swigCPtr", "J");
    jlong swigCPtr = (*env)->GetLongField(env, jarg1, ptrField);

    go_slice *slice = (go_slice *) (intptr_t) swigCPtr;
    slice->ptr = nativeMemory;
    slice->len = (uintptr_t) byteArrayLen;
    slice->cap = (uintptr_t) byteArrayLen;

    (*env)->ReleaseByteArrayElements(env, jarg1_, nativeBytes, 0);
}

JNIEXPORT jbyteArray JNICALL
Java_com_silencelaboratories_godilithium_GoSliceUtilJNI_get_1bytes_1from_1go_1slice(
        JNIEnv *env, jobject obj, jobject jarg1) {
    jclass goSliceClass = (*env)->GetObjectClass(env, jarg1);
    jfieldID ptrField = (*env)->GetFieldID(env, goSliceClass, "swigCPtr", "J");
    jlong swigCPtr = (*env)->GetLongField(env, jarg1, ptrField);

    go_slice *slice = (go_slice *) (intptr_t) swigCPtr;

    jsize len = (jsize) slice->len;
    jbyteArray byteArray = (*env)->NewByteArray(env, len);
    if (byteArray == NULL) {
        return NULL;
    }

    (*env)->SetByteArrayRegion(env, byteArray, 0, len, (const jbyte *) slice->ptr);
    return byteArray;
}