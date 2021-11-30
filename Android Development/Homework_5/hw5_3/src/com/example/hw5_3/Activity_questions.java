package com.example.hw5_3;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.CompoundButton.OnCheckedChangeListener;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

public class Activity_questions extends Activity {
	String gender, agestr, occupation;
	int age;
    Bundle bundle;
    //private RadioButton ;
    TextView xxx;
    private RadioGroup q_group1, q_group2, q_group3, q_group4, q_group5, q_group6;
    private RadioButton q1_coke, q1_juice, q1_tea, q1_others;
    private int q1ans = 1, q2ans = 1, q3ans = 1, q4ans = 1, q5ans = 1, q6ans = 1;
  protected void onCreate(Bundle savedInstanceState) {   
	super.onCreate(savedInstanceState);
    setContentView(R.layout.questions);  
    bundle = this.getIntent().getExtras();
    if (bundle != null) {
    	gender = bundle.getString("GENDER");
    	agestr = bundle.getString("AGE");
		age = Integer.parseInt(agestr.equalsIgnoreCase("") ? "0" : agestr);
    	occupation = bundle.getString("OCCUPATION");
    } // 取得第一個表單的資料
    xxx = (TextView)findViewById(R.id.xxx); 
    q_group1 = (RadioGroup)findViewById(R.id.radioGroup1);
    q_group2 = (RadioGroup)findViewById(R.id.radioGroup2);
    q_group3 = (RadioGroup)findViewById(R.id.radioGroup3);
    q_group4 = (RadioGroup)findViewById(R.id.radioGroup4);
    q_group5 = (RadioGroup)findViewById(R.id.radioGroup5);
    q_group6 = (RadioGroup)findViewById(R.id.radioGroup6);

    q_group1.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
	  @Override
	  public void onCheckedChanged(RadioGroup q_group1, int checkedId) {
		int id= q_group1.getCheckedRadioButtonId();
		switch (q_group1.getCheckedRadioButtonId()) {
		  case R.id.q1_coke:
			q1ans = 1;
		  break;
		  case R.id.q1_juice:
			  q1ans = 2;
			break;
		  case R.id.q1_tea:
			  q1ans = 3;
			break;
		  case R.id.q1_others:
			  q1ans = 4;
			break;
		}			
	  }    
    }); 
    q_group2.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
	  @Override
	  public void onCheckedChanged(RadioGroup q_group2, int checkedId) {
		int id= q_group2.getCheckedRadioButtonId();
		switch (q_group2.getCheckedRadioButtonId()) {
		  case R.id.q2_surface:
			q2ans = 1;
		    break;
		  case R.id.q2_rice:
			q2ans = 2;
		    break;
		  case R.id.q2_bread:
			q2ans = 3;
			break;
		  case R.id.q2_others:
			q2ans = 4;
			break;
		}			
	  }    
    });     

    q_group3.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
	  @Override
	  public void onCheckedChanged(RadioGroup q_group3, int checkedId) {
		int id= q_group3.getCheckedRadioButtonId();
		switch (q_group3.getCheckedRadioButtonId()) {
		  case R.id.q3_horror:
			q3ans = 1;
		    break;
		  case R.id.q3_action:
			q3ans = 2;
		    break;
		  case R.id.q3_love:
			q3ans = 3;
			break;
		  case R.id.q3_others:
			q3ans = 4;
			break;
		}			
	  }    
    }); 
    
    q_group4.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
	  @Override
	  public void onCheckedChanged(RadioGroup q_group4, int checkedId) {
		int id= q_group4.getCheckedRadioButtonId();
		switch (q_group4.getCheckedRadioButtonId()) {
		  case R.id.q4_rock:
			q4ans = 1;
		    break;
		  case R.id.q4_ballad:
			q4ans = 2;
		    break;
		  case R.id.q4_jazz:
			q4ans = 3;
			break;
		  case R.id.q4_others:
			q4ans = 4;
			break;
		}			
	  }    
    });    

    q_group5.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
	  @Override
	  public void onCheckedChanged(RadioGroup q_group5, int checkedId) {
		int id= q_group5.getCheckedRadioButtonId();
		switch (q_group5.getCheckedRadioButtonId()) {
		  case R.id.q5_ps3:
			q5ans = 1;
		    break;
		  case R.id.q5_xbox360:
			q5ans = 2;
		    break;
		  case R.id.q5_wii:
			q5ans = 3;
			break;
		  case R.id.q5_others:
			q5ans = 4;
			break;
		}			
	  }    
    });
    
    q_group6.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
	  @Override
	  public void onCheckedChanged(RadioGroup q_group6, int checkedId) {
		int id= q_group6.getCheckedRadioButtonId();
		switch (q_group6.getCheckedRadioButtonId()) {
		  case R.id.q6_ea:
			q6ans = 1;
		    break;
		  case R.id.q6_ubisoft:
			q6ans = 2;
		    break;
		  case R.id.q6_capcom:
			q6ans = 3;
			break;
		  case R.id.q6_square:
			q6ans = 4;
			break;
		}			
	  }    
    }); 
    
  }
  public void click_submit(View view){
	//String s = "asn1 = "+q1ans + " asn2 = "+q2ans + " asn3 = "+q3ans + " asn4 = "+q4ans + " asn5 = "+q5ans + " asn6 = "+q6ans;
    //xxx.setText(s);
	Intent intent = new Intent();
	intent.setClass(Activity_questions.this, Activity_showone.class);
	Bundle bun = new Bundle();
	bun.putString("GENDER", gender);
	bun.putInt("AGE", age);
	bun.putString("OCCUPATION", occupation);
	bun.putInt("Q1", q1ans);
	bun.putInt("Q2", q2ans);
	bun.putInt("Q3", q3ans);
	bun.putInt("Q4", q4ans);
	bun.putInt("Q5", q5ans);
	bun.putInt("Q6", q6ans);
	intent.putExtras(bun);  
	startActivity(intent);
  }  
}
