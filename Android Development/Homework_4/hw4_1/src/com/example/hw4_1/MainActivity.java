package com.example.hw4_1;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.KeyEvent; 
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
  private EditText nameinput;
  private EditText playsinput;
  private TextView nameoutput;
  private TextView playsoutput;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
	  super.onCreate(savedInstanceState);
	  setContentView(R.layout.activity_main);
	  nameinput = (EditText)findViewById(R.id.player_name);
	  playsinput = (EditText)findViewById(R.id.plays);
	  nameoutput = (TextView)findViewById(R.id.welcome_player);
	  playsoutput = (TextView)findViewById(R.id.plays_ouput);		
	  nameinput.setOnKeyListener(new EditText.OnKeyListener(){
		@Override
		public boolean onKey(View view, int keycode, KeyEvent event) {
		  String str = "";
		  str = nameinput.getText()+", Welcome to Lucky Wheel!";
		  nameoutput.setText(str);
		  return false;
		} 	  
	  });
	  playsinput.setOnKeyListener(new EditText.OnKeyListener(){
		@Override
		public boolean onKey(View view2, int keycode2, KeyEvent event2) {
		  String str = "";
		  str = "Number of plays: "+playsinput.getText();
		  playsoutput.setText(str);			
		  return false;
		}
	  });
	  	
	}  // onCreate
	public void onclick_go(View view){
      Intent intent = new Intent();
      intent.setClass(MainActivity.this, wheel_activity.class);
      Bundle bundle = new Bundle();
	  bundle.putString("PLAYS", playsinput.getText().toString());
	  intent.putExtras(bundle);  
	  startActivity(intent);
	  this.finish();
	}
    public void exit_Click(View view){
      this.finish();	
    }
}
