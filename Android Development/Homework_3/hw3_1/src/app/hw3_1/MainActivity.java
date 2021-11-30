package app.hw3_1;

import android.os.Bundle;
import android.app.Activity;
import android.content.res.Resources;
import android.graphics.drawable.AnimationDrawable;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
	  super.onCreate(savedInstanceState);
	  setContentView(R.layout.activity_main);
	  Button playbutton = (Button)findViewById(R.id.button1);
	  playbutton.setOnClickListener(playlistener);
	}

	private OnClickListener playlistener = new OnClickListener(){
	  public void onClick(View v) {
		Resources res = getResources();	 // 首先呼叫getResources()方法取得資源物件
		AnimationDrawable anim = (AnimationDrawable)res.getDrawable(R.drawable.anim_drawable);  
		  //再利用資源物件的getDrawable()方法取得Frame animation動畫資源檔（假設檔名為anim_drawable.xml）	
		ImageView animimgview = (ImageView)findViewById(R.id.imageView1);
		animimgview.setImageDrawable(anim);
		anim.start();
	  }
		
	};

}
