package com.example.hw5_3;

import android.app.Activity;
import android.os.Bundle;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class Activity_showone extends Activity {
  Bundle bundle;
  String gender, occupation;
  int age;
  int q1ans = 1, q2ans = 1, q3ans = 1, q4ans = 1, q5ans = 1, q6ans = 1;
  TextView output;
  protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.show_one);
    bundle = this.getIntent().getExtras();
    if (bundle != null) {
      gender = bundle.getString("GENDER");
      age = bundle.getInt("AGE");
      occupation = bundle.getString("OCCUPATION");
      q1ans = bundle.getInt("Q1");
      q2ans = bundle.getInt("Q2");
      q3ans = bundle.getInt("Q3");
      q4ans = bundle.getInt("Q4");
      q5ans = bundle.getInt("Q5");
      q6ans = bundle.getInt("Q6");  	
    }
    String str = "";
    output = (TextView)findViewById(R.id.showone_gender);
    str = "Gender:"+gender;
    output.setText(str);
    output = (TextView)findViewById(R.id.showone_age);
    str = "Age:"+age;
    output.setText(str);    
    output = (TextView)findViewById(R.id.showone_occupation);
    str = "Occupation:"+occupation;
    output.setText(str);    
    output = (TextView)findViewById(R.id.all_ans);
    str = "";
    str = "1)"+q1ans+"    2)"+q2ans+"    3)"+q3ans+"    4)"+q4ans+"    5)"+q5ans+"    6)"+q6ans;
    output.setText(str);
  }

}
