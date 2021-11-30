package com.example.hw5_3;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class NewListDataSQL extends SQLiteOpenHelper {

	public NewListDataSQL(Context context) {
	  super(context, "dbfrom", null, 1);
	  // TODO Auto-generated constructor stub
	}
	@Override
	public void onCreate(SQLiteDatabase db) {
		// TODO Auto-generated method stub
	  String sql = 
	    "CREATE TABLE formsdata(_ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,"+
	    "gender VARCHAR,"+
	    "age INT,"+
	    "occupation VARCHAR,"+
	    "q1 INT,"+
	    "q2 INT,"+
	    "q3 INT,"+
	    "q4 INT,"+
	    "q5 INT,"+
	    "q6 INT,"+")";
	  db.execSQL(sql);	
	}
	@Override
	public void onUpgrade(SQLiteDatabase db, int oldversion, int newversion) {
		// TODO Auto-generated method stub
	}

}
