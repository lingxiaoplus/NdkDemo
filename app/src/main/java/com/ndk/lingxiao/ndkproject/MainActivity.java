package com.ndk.lingxiao.ndkproject;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Hello hello = new Hello();
        Hello.callStaticMethod(100);
        hello.callInstanceMethod(1);

        hello.callJavaStaticMethod();
        hello.callJavaInstanceMethod();

        Log.d(TAG, "before change name   "+hello.name);
        hello.changeField();
        Log.d(TAG, "after change name   "+hello.name);

        Log.d(TAG, "before change age   "+hello.age);
        hello.changeStaticField();
        Log.d(TAG, "after change age   "+hello.age);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI());
    }

}
