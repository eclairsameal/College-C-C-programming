package com.example.hw5_3;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends Activity {

  @Override
  protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.activity_main);
  }

  public void click_submit(View view){
  	EditText editgender = (EditText) findViewById(R.id.editText_Gender);
  	EditText editage = (EditText) findViewById(R.id.editText_Age);
  	EditText editoccupation = (EditText) findViewById(R.id.editText_Occupation);
	
  	Intent intent = new Intent();
	intent.setClass(MainActivity.this, Activity_questions.class);
	Bundle bundle = new Bundle();
	bundle.putString("GENDER", editgender.getText().toString());
	bundle.putString("AGE", editage.getText().toString());
	bundle.putString("OCCUPATION", editoccupation.getText().toString());
	intent.putExtras(bundle);  
	startActivity(intent);   	  
  }
}
