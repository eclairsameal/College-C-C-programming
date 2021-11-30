package app.hw2_2;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
	  super.onCreate(savedInstanceState);
	  setContentView(R.layout.activity_main);
	  Button button = (Button)findViewById(R.id.button1);
	  button.setOnClickListener(listener);
	}
    private OnClickListener listener = new OnClickListener(){
      public void onClick(View view){
    	EditText editname = (EditText) findViewById(R.id.name);
    	EditText editaddress = (EditText) findViewById(R.id.address);
    	EditText editphonenumber = (EditText) findViewById(R.id.phonenumber);
    	
    	EditText editproduct_num1 = (EditText) findViewById(R.id.product_num1);
    	EditText editproduct_num2 = (EditText) findViewById(R.id.product_num2);
    	EditText editproduct_num3 = (EditText) findViewById(R.id.product_num3);
    	EditText editproduct_num4 = (EditText) findViewById(R.id.product_num4);

    	
    	Intent intent = new Intent();
    	intent.setClass(MainActivity.this, Activity_receipt.class);
    	Bundle bundle = new Bundle();
		bundle.putString("NAME", editname.getText().toString());
		bundle.putString("ADDRESS", editaddress.getText().toString());
		bundle.putString("PHONE", editphonenumber.getText().toString());
		bundle.putString("PRODUCT1", editproduct_num1.getText().toString());
		bundle.putString("PRODUCT2", editproduct_num2.getText().toString());
		bundle.putString("PRODUCT3", editproduct_num3.getText().toString());
		bundle.putString("PRODUCT4", editproduct_num4.getText().toString());
		intent.putExtras(bundle);  
		startActivity(intent);     	
      }
    };

}
