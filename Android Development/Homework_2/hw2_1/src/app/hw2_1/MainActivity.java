package app.hw2_1;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.lang.Math;

public class MainActivity extends Activity {
	String randomstr;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
	  super.onCreate(savedInstanceState);
	  setContentView(R.layout.activity_main);
	  String word[] = {"SCARLET", "Synchrogazer", "KOTOKO", "SUPERNAL", "BLAZE","KILL", "PSYCHO", "LOVE", "FATE", "LIBERTY"};
	  int rand_word = (int)(Math.random()*10);
	  randomstr = word[rand_word];
	  TextView ansoutput = (TextView) findViewById(R.id.garbled);
	  int len = randomstr.length(), char_rand;
	  char char_word[];;
	  boolean word_b[];
	  char_word = new char[len];
	  word_b = new boolean[len];
	  for(int i = 0; i < len; i++){word_b[i] = false;}
	  
	  for(int i = 0; i < len; i++){
		char_rand = (int)(Math.random()*len);
		while(word_b[char_rand] == true){char_rand = (int)(Math.random()*len);}
		char_word[i] = randomstr.charAt(char_rand);
		word_b[char_rand] = true;
	  }
	  
	  String str = new String(char_word);
	  ansoutput.setText(str);
	  Button guessbutton = (Button)findViewById(R.id.guess_button);
	  guessbutton.setOnClickListener(guesslistener);
	}

    private OnClickListener guesslistener = new OnClickListener(){
      public void onClick(View view){
    	EditText editans = (EditText) findViewById(R.id.ans);
    	String ansString = editans.getText().toString();
    	TextView output = (TextView) findViewById(R.id.textView4);
    	int flag;
    	flag = randomstr.compareTo(ansString);
    	if(flag==0){  
    	  output.setText("Correct!");
    	}
    	else{
    	  output.setText("Incorrect! Try again!");
    	}
    	
      }
    };
    public void exit_Click(View view){
      this.finish();	
    }
    public void new_Click(View view){
      Intent intent =new Intent();
      intent.setClass(MainActivity.this,MainActivity.class);
      startActivity(intent);
      this.finish();
    }
}
