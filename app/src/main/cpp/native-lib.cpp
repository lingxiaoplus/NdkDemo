#include <jni.h>
#include <string>
extern "C" JNIEXPORT jstring

JNICALL
Java_com_ndk_lingxiao_ndkproject_Hello_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ndk_lingxiao_ndkproject_Hello_callStaticMethod__I(JNIEnv *env, jclass type, jint i) {

}