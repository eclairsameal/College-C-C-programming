package app.hw2_2;

import android.app.Activity;
import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class Activity_receipt extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_receipt);
		receipt();
	}
	private void receipt() {
	  int product_num1, product_num2, product_num3, product_num4, total = 0;
	  String  name, address, phone, st;
      Bundle bundle = this.getIntent().getExtras();
	  if (bundle != null) {
		st = bundle.getString("PRODUCT1");
		product_num1 = Integer.parseInt(st.equalsIgnoreCase("") ? "0" : st);
		st = bundle.getString("PRODUCT2");
		product_num2 = Integer.parseInt(st.equalsIgnoreCase("") ? "0" : st);
		st = bundle.getString("PRODUCT3");
		product_num3 = Integer.parseInt(st.equalsIgnoreCase("") ? "0" : st);
		st = bundle.getString("PRODUCT4");
		product_num4 = Integer.parseInt(st.equalsIgnoreCase("") ? "0" : st);
		 
		name = bundle.getString("NAME");
		address = bundle.getString("ADDRESS");
		phone = bundle.getString("PHONE");
		
		
		TextView output = (TextView) findViewById(R.id.customer_name);
		output.setText("     "+name);
		output = (TextView) findViewById(R.id.customer_address);
		output.setText("     "+address);
		output = (TextView) findViewById(R.id.customer_phone);
		output.setText("     "+phone);
		
		
		output = (TextView) findViewById(R.id.product_num1);
		output.setText("   "+Integer.toString(product_num1));		
		output = (TextView) findViewById(R.id.product_num2);
		output.setText("   "+Integer.toString(product_num2));	
		output = (TextView) findViewById(R.id.product_num3);
		output.setText("   "+Integer.toString(product_num3));	
		output = (TextView) findViewById(R.id.product_num4);
		output.setText("   "+Integer.toString(product_num4));
		
		int cost = 0;
		output = (TextView) findViewById(R.id.product_cost1);
		cost = product_num1 * 1390;
		total+= cost;
		output.setText(Integer.toString(cost));
		output = (TextView) findViewById(R.id.product_cost2);
		cost = product_num2 * 1790;
		total+= cost;
		output.setText(Integer.toString(cost));
		output = (TextView) findViewById(R.id.product_cost3);
		cost = product_num3 * 1890;
		total+= cost;
		output.setText(Integer.toString(cost));
		output = (TextView) findViewById(R.id.product_cost4);
		cost = product_num4 * 1590;
		total+= cost;
		output.setText(Integer.toString(cost));
		
		output = (TextView) findViewById(R.id.total_cost);
		output.setText(Integer.toString(total));		
	  }
	}
}
