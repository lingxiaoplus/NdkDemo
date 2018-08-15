package com.ndk.lingxiao.ndkproject;

import android.util.Log;

public class Hello {
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
    public static native void callStaticMethod(int i);
    public static native void callStaticMethod(long i,String str);

    public  native void callInstanceMethod(int i);
    public  native void callInstanceMethod(String str,long i);

}
