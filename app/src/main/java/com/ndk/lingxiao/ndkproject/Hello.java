package com.ndk.lingxiao.ndkproject;

import android.util.Log;

public class Hello {
    public String name = "im is java";
    public static int age = 11;
    static {
        System.loadLibrary("native-lib");
    }
    public static native String stringFromJNI();

    public static void logMessage(String data){
        Log.d("hello", data);
    }

    public static void staticMethod(String data){
        logMessage(data);
    }

    public void instanceMethod(String data){
        logMessage(data);
    }

    public native void callInstanceMethod(int i);
    public static native void callStaticMethod(int i);


    public native void callJavaStaticMethod();
    public native void callJavaInstanceMethod();

    public native void changeField();
    public native void changeStaticField();

}
