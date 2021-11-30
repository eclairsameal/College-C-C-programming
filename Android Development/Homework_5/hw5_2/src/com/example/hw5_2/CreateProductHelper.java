package com.example.hw5_2;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class CreateProductHelper extends SQLiteOpenHelper {

	public CreateProductHelper(Context context) {
	  super(context, "dbaddress", null, 1);
	  // TODO Auto-generated constructor stub
	}

	@Override
	public void onCreate(SQLiteDatabase db) {
		// TODO Auto-generated method stub
	  String sql = 
	    "CREATE TABLE dbtable (_id integer primary key autoincrement,"+
	    "name text no null, phone text no null, email text no null)";	  
	  db.execSQL(sql);
		
	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldversion, int newversion) {
		// TODO Auto-generated method stub
	}

}
