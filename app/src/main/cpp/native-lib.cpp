#include <jni.h>
#include <string>
#include <android/log.h>
#define LOG_TAG "NATIVE_LIB"

#define DEBUG
#define ANDROID_PLATFORM

#ifdef DEBUG
#ifdef ANDROID_PLATFORM
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))
#else
#define LOGD(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#define LOGI(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#define LOGW(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#define LOGE(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#endif
#else
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#endif
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
Java_com_ndk_lingxiao_ndkproject_Hello_callStaticMethod(JNIEnv *env, jclass type, jint i) {
    LOGE("im from static moethod, value is : %d",i);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ndk_lingxiao_ndkproject_Hello_callInstanceMethod
        (JNIEnv *, jobject, jint i){
    LOGE("im from instance moethod, value is : %d",i);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ndk_lingxiao_ndkproject_Hello_callJavaStaticMethod(JNIEnv *env, jclass type) {
    jclass clazz = NULL;
    jmethodID method_id = NULL;
    jstring str_log = NULL;

    clazz = env->FindClass("com/ndk/lingxiao/ndkproject/Hello");
    if (clazz == NULL){
        LOGD("没有发现该类");
        return;
    }
    method_id = env->GetStaticMethodID(clazz,"staticMethod","(Ljava/lang/String;)V");
    if (method_id == NULL){
        LOGD("没有发现该方法名");
        return;
    }
    str_log = env->NewStringUTF("c++ 调用java的静态方法");
    env->CallStaticVoidMethod(clazz,method_id,str_log);

    env->DeleteLocalRef(clazz);
    env->DeleteLocalRef(str_log);
    return ;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_ndk_lingxiao_ndkproject_Hello_callJavaInstanceMethod(JNIEnv *env, jobject instance) {
    jclass clazz = NULL;
    jmethodID method_id = NULL;
    jstring str_log = NULL;

    clazz = env->FindClass("com/ndk/lingxiao/ndkproject/Hello");
    if (clazz == NULL){
        LOGD("没有发现该类");
        return;
    }
    method_id = env->GetMethodID(clazz,"instanceMethod","(Ljava/lang/String;)V");
    if (method_id == NULL){
        LOGD("没有发现该方法名");
        return;
    }
    str_log = env->NewStringUTF("c++ 调用java的实例方法");
    env->CallVoidMethod(instance,method_id,str_log);
    env->DeleteLocalRef(clazz);
    env->DeleteLocalRef(str_log);
    env->DeleteLocalRef(instance);
    return ;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ndk_lingxiao_ndkproject_Hello_changeField(JNIEnv *env, jobject instance) {
    jclass clazz = env->GetObjectClass(instance);
    if (clazz == NULL){
        return;
    }
    jfieldID jfieldID = env->GetFieldID(clazz,"name","Ljava/lang/String;");
    if (jfieldID == NULL){
        return;
    }
    jstring obj_str = (jstring) env->GetObjectField(instance,jfieldID);
    if (obj_str == NULL){
        return;
    }
    char* c_str = (char*) env->GetStringUTFChars(obj_str,JNI_FALSE);

    const char new_char[40] = "changed from c";
    //复制new_char的内容到c_str
    strcpy(c_str,new_char);

    jstring new_str = env->NewStringUTF(c_str);
    LOGD("%s",new_char);
    env->SetObjectField(instance,jfieldID,new_str);

    env->DeleteLocalRef(clazz);
    env->DeleteLocalRef(obj_str);
    env->DeleteLocalRef(new_str);
    return;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ndk_lingxiao_ndkproject_Hello_changeStaticField(JNIEnv *env, jclass type) {
    jclass clazz = env->FindClass("com/ndk/lingxiao/ndkproject/Hello");
    if (clazz == NULL){
        return;
    }
    jfieldID jfieldID = env->GetStaticFieldID(clazz,"age","I");
    if (jfieldID == NULL){
        return;
    }
    int age = env->GetStaticIntField(clazz,jfieldID);
    LOGD("%d",age);
    jint change_int = 12;
    env->SetStaticIntField(clazz,jfieldID,change_int);

    env->DeleteLocalRef(clazz);
}
