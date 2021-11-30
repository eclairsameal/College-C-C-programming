package com.example.hw4_2;

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
  public void onclick_go(View view){
	EditText editsize = (EditText)findViewById(R.id.size);
	Bundle bundle = new Bundle();
	Intent intent = new Intent();
	intent.setClass(MainActivity.this, guessing_activity.class);
	bundle.putString("SIZE", editsize.getText().toString());
	intent.putExtras(bundle);
	startActivity(intent);
	this.finish();	
  }
  public void onclick_exit(View view){
	this.finish();  
  }
}
