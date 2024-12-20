#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "go-dkls.h"  // Include your tss_buffer struct definition

JNIEXPORT void JNICALL
Java_com_silencelaboratories_godkls_BufferUtilJNI_set_1bytes_1on_1tss_1buffer(JNIEnv *env,
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
Java_com_silencelaboratories_godkls_BufferUtilJNI_get_1bytes_1from_1tss_1buffer(
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

JNIEXPORT void JNICALL
Java_com_silencelaboratories_godkls_BufferUtilJNI_set_1bytes_1on_1go_1slice(JNIEnv *env,
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

    go_slice *buffer = (go_slice *) (intptr_t) swigCPtr;
    buffer->ptr = nativeMemory;
    buffer->len = (uintptr_t) byteArrayLen;
    buffer->cap = (uintptr_t) byteArrayLen;

    (*env)->ReleaseByteArrayElements(env, jarg1_, nativeBytes, 0);
}

JNIEXPORT jbyteArray JNICALL
Java_com_silencelaboratories_godkls_BufferUtilJNI_get_1bytes_1from_1go_1slice(
        JNIEnv *env, jobject obj, jobject jarg1) {
    jclass goSliceClass = (*env)->GetObjectClass(env, jarg1);
    jfieldID ptrField = (*env)->GetFieldID(env, goSliceClass, "swigCPtr", "J");
    jlong swigCPtr = (*env)->GetLongField(env, jarg1, ptrField);

    go_slice *buffer = (go_slice *) (intptr_t) swigCPtr;

    jsize len = (jsize) buffer->len;
    jbyteArray byteArray = (*env)->NewByteArray(env, len);
    if (byteArray == NULL) {
        return NULL;
    }

    (*env)->SetByteArrayRegion(env, byteArray, 0, len, (const jbyte *) buffer->ptr);
    return byteArray;
}