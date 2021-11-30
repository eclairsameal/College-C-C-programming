package com.example.hw4_2;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

public class guessing_activity extends Activity implements View.OnClickListener{
	
  int size, p_point = 0, c_point = 0;
  int[] value;
  Button button[];
  LinearLayout layout;
  TextView text2, text_pp, text_cp, text1;
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.guessing_game);
    
	String str;
	Bundle bundle = this.getIntent().getExtras();
	if (bundle != null) {
	  str = bundle.getString("SIZE");
	  size = Integer.parseInt(str.equalsIgnoreCase("") ? "0" : str);
	}
	value= new int[size * size];
	button = new Button[size * size];
	for(int i = 0; i < size * size; i++){
	  value[i] = (int)(Math.random()*(size * size)) + 1;
	  for(int j = 0; j < i; j++){
		if(value[i]==value[j]){
		  i--;
		  break;
		}  
	  }
	}
	
    LinearLayout mainlinearlayout = (LinearLayout)findViewById(R.id.linear_layout);
    int buttonnumber = 0; // buttonnumber 設定物件ID 
    for(int i = 0; i < size; i++){
      layout = new LinearLayout(this);	
      layout.setOrientation(LinearLayout.HORIZONTAL);
      mainlinearlayout.addView(layout);
      for(int j = 0; j < size; j++){
		button[buttonnumber] = new Button(this);
		button[buttonnumber].setText("");
		button[buttonnumber].setId(buttonnumber);
		
		button[buttonnumber].setOnClickListener((OnClickListener) this);

    	layout.addView(button[buttonnumber]);
    	buttonnumber++;
      }    	   	
    }  // 將動態陣列給家道視窗中 跟設定相關值  */
    text1 = new TextView(this);
    text2 = new TextView(this);
    text_cp = new TextView(this);
    text_pp = new TextView(this);
    text1.setText(" ");
    text2.setText(" ");
    text_cp.setText(" ");
    text_pp.setText(" ");
    mainlinearlayout.addView(text1);
    mainlinearlayout.addView(text2);
    mainlinearlayout.addView(text_cp);
    mainlinearlayout.addView(text_pp); 	
  }
  
  int play_count = 0;
  public void onClick(View view) {
	play_count++;
	int c_rand = (int)(Math.random()*(size * size));
	int v = view.getId();
	int p_value = value[v];
	p_point += p_value;
	((Button) view).setText(""+p_value);
	((Button) view).setEnabled(false);
    while(button[c_rand].isEnabled()==false){
   	  c_rand=(int)(Math.random()*(size * size));
    }
	int c_value = value[c_rand];
	c_point += c_value;
	button[c_rand].setText(""+c_value);
	button[c_rand].setEnabled(false);
	 
	String str = "";
	str = "Yours: "+p_value+"  Computer: "+c_value; 
	text1.setText(str);
	if(p_value > c_value){str = "You won."; text2.setText(str); }
	else{str = "You lost."; text2.setText(str);}
	str = "Your Points: "+p_point;
	text_cp.setText(str);
	str = "Computer's Points: "+c_point;
	text_pp.setText(str);
	int n = (int)((size*size)/2);
	if(play_count >= n){
	  str = "Your Points: "+p_point;
	  text1.setText(str);
	  str = "Computer's Points: "+c_point;
	  text2.setText(str);
	  if(p_point > c_point){str = "You won the game! "; text_cp.setText(str);}
	  else{str = "You lost the game!"; text_cp.setText(str);}
	  text_pp.setText(" ");
	  int i = 0;
	  while(i < size*size){
		if(button[i].isEnabled()==true){button[i].setEnabled(false);}
		i++;
	  }
	} 
 }
   
}

  

