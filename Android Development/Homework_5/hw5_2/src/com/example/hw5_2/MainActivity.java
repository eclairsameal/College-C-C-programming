package com.example.hw5_2;

import android.os.Bundle;
import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends Activity {
  private static String DATABASE_TABLE = "dbtable";
  private SQLiteDatabase db;
  private CreateProductHelper helper;
  private EditText txtName, txtPhone, txtEmail;
  private TextView output;
  @Override
  protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.activity_main);
    
	helper = new CreateProductHelper(this);
    db = helper.getWritableDatabase(); 
	
    output = (TextView) findViewById(R.id.textoutput);
    txtName=(EditText) findViewById(R.id.editText_name);
    txtPhone=(EditText) findViewById(R.id.editText_phone);
    txtEmail=(EditText) findViewById(R.id.editText_email);		
			
	}

  public void insert_Click(View view) {
	db.beginTransaction();
	ContentValues val = new ContentValues();
	val.put("name", txtName.getText().toString());
	val.put("phone", txtPhone.getText().toString());
	val.put("email", txtEmail.getText().toString());
	db.insert("dbtable", null, val);
    db.setTransactionSuccessful();
	db.endTransaction();
	output.setText("新增資料");
  }
  public void deldte_Click(View view) {
	String str = null;
	try{
	  str = "name = '" + txtName.getText().toString()+"'";
	  db.beginTransaction();
	  db.delete("dbtable", str, null);
	  db.setTransactionSuccessful();
      db.endTransaction();	  
	  output.setText("刪除成功");
	}catch(Exception e){
	  output.setText("刪除失敗");
	  Log.e("ERROR",e.toString());
	}
  }
  public void query_Click(View view) {
	String str = null;
	String[] colNames;  
	try{
	  str = "name = '" + txtName.getText().toString()+"'";  
	  Cursor c = db.rawQuery("SELECT * FROM dbtable WHERE "+ str, null);
	  colNames = c.getColumnNames();
	  str = "";
	  for (int i = 1; i < colNames.length; i++)
	  	str += colNames[i] + "\t\t";
	  str += "\n";
	  c.moveToFirst(); 
	  	str += c.getString(1) + "\t\t";
	  	str += c.getString(2) + "\t\t";
	  	str += c.getString(3) + "\n";
	  	output.setText(str.toString());			
      }catch(Exception e){
  		output.setText("失敗");
  		Log.e("ERROR",e.toString());  
      } 
  }
  public void update_Click(View view) {
	String str = null;
	try{
	  str = "name = '" + txtName.getText().toString()+"'";
	  db.beginTransaction();
	  ContentValues val = new ContentValues();
	  val.put("phone", txtPhone.getText().toString());
	  val.put("email", txtEmail.getText().toString());
	  db.update("dbtable", val, str, null);
	  db.setTransactionSuccessful();
	  db.endTransaction();	  
	  output.setText("更新成功");
	} catch(Exception e){
		output.setText("更新失敗");
		Log.e("ERROR",e.toString());		
	  }		
  }
  
  public void list_Click(View view) {
	String[] colNames;
  	String str = "";    	
  	Cursor c = db.rawQuery("SELECT * FROM " + DATABASE_TABLE, null);
  	colNames = c.getColumnNames();
    for (int i = 1; i < colNames.length; i++)
  		str += colNames[i] + "\t\t";
  	str += "\n";
  	c.moveToFirst(); 
  	for (int i = 0; i < c.getCount(); i++) {
  		str += c.getString(1) + "\t\t";
  		str += c.getString(2) + "\t\t";
  		str += c.getString(3) + "\n";
  		c.moveToNext();
  	}
  	output.setText(str.toString()); 
  }
  
}
