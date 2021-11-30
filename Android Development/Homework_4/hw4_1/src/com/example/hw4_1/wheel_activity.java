package com.example.hw4_1;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;


public class wheel_activity extends Activity {
  int plays, cost = 100, count = 0;	
  protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.wheel);   // 新的XML資源檔
	String str;
	Bundle bundle = this.getIntent().getExtras();
	if (bundle != null) {
	  str = bundle.getString("PLAYS");
	  plays = Integer.parseInt(str.equalsIgnoreCase("") ? "0" : str);
	}
	TextView tv1 = (TextView)findViewById(R.id.textView3);
	tv1.setVisibility(View.GONE);
	Button bv = (Button)findViewById(R.id.newgame);
	bv.setVisibility(View.GONE);
	bv = (Button)findViewById(R.id.exit);
	bv.setVisibility(View.GONE);
  }
  public void onclick_go2(View view){
	int rand_prize = 0, n = 0;
	String str = "";
	TextView titlecost = (TextView)findViewById(R.id.textView2);
	TextView tv1 = (TextView)findViewById(R.id.textView3);
	rand_prize = (int)(Math.random() * 11 + 1);
	game(rand_prize);
	count++;
	if(count == plays){
	  n = cost - 100;
	  if(n >= 0){ 
	    str = "Total pay: "+cost+"  You won: "+n;
	    titlecost.setText(str);		  
	  }
	  else{
		n = Math.abs(cost) - 100;
	    str = "Total pay: "+cost+"  You loat: "+n;
	    titlecost.setText(str);		  
	  }
	  tv1.setVisibility(View.VISIBLE);
	  Button bv = (Button)findViewById(R.id.newgame);
	  bv.setVisibility(View.VISIBLE);
	  bv = (Button)findViewById(R.id.exit);
      bv.setVisibility(View.VISIBLE);
      bv = (Button)findViewById(R.id.go);
      bv.setVisibility(View.GONE);
	}
  }
  private void game(int rand_prize){
	String str = "";
	TextView output = (TextView)findViewById(R.id.textView1);
	TextView colar;
	switch (rand_prize){
      case 1: cost += 100;
        str = "Your roll is 1. You won 100.";
        colar = (TextView)findViewById(R.id.prize_1);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 2: cost -= 100;
        str = "Your roll is 2. You lost 100.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_2);
        colar.setBackgroundColor(0xFFFFFF00);
        break;
      case 3: cost += 1000;
        str = "Your roll is 3. You won 1000.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_3);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 4: cost = 0;
        str = "Your roll is 4. You lost all.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_4);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 5: cost += 500;
        str = "Your roll is 5. You won 500.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_5);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 6: cost -= 300;
        str = "Your roll is 6. You lost 300.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_6);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 7: cost += 200;
        str = "Your roll is 7. You won 200.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_7);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 8: cost -= 1000;
        str = "Your roll is 8. You lost 1000.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_8);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 9: cost += 250;
        str = "Your roll is 9. You won 250.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_9);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 10: cost -= 250;
        str = "Your roll is 10. You lost 250.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_10);
        colar.setBackgroundColor(0xFFFFFF00);
        break;  
      case 11: cost -= 200;
        str = "Your roll is 11. You lost 200.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_11);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
      case 12: cost += 300;
        str = "Your roll is 12. You won 300.";
        output.setText(str);
        colar = (TextView)findViewById(R.id.prize_12);
        colar.setBackgroundColor(0xFFFFFF00);
        break; 
	  }  
  }
  
  public void onclick_new(View view){
    Intent intent =new Intent();
    intent.setClass(wheel_activity.this,MainActivity.class);
    startActivity(intent);
    this.finish();   	
  } 
  public void onclick_exit(View view){
	  android.os.Process.killProcess(android.os.Process.myPid()) ; 
  }  
   /////////////////////////////////////  
}
