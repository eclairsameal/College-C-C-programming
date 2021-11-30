package com.example.pet;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends Activity implements OnClickListener{
	ImageView myImageView = null;
	TextView myTextView = null;
	Button touch = null; // 撫摸按鈕
	Button bath = null; // 洗澡按鈕
	Button eat = null; // 餵養按鈕
	Button find = null; //尋找按鈕 
	GameDog gameDog;//GameDog的物件變數
	ActionThread actionThread;//後台線程的物件變數
	Handler myHandler = new Handler(){//用來更新UI線程中的控件
        public void handleMessage(Message msg) {
        	switch(msg.what){
        		case 1://為後台線程發來的訊息
        			gameDog.updateState(MasterAction.ALONE_ACTION);//長時間無人搭理
        			break;
        	}
        }
	};
	public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        myImageView = (ImageView) this.findViewById(R.id.myImageView);
        myTextView = (TextView) this.findViewById(R.id.myTextView);
        touch = (Button) this.findViewById(R.id.touch);
        bath = (Button) this.findViewById(R.id.bath);
        eat = (Button) this.findViewById(R.id.eat);
        find = (Button) this.findViewById(R.id.find);
        
        touch.setOnClickListener(this);
        bath.setOnClickListener(this);
        eat.setOnClickListener(this);
        find.setOnClickListener(this);
        
        gameDog = new GameDog(this);
        actionThread = new ActionThread(this);
        actionThread.start();//啟動後台線程
    }
	public void onClick(View v) {
		if(v == touch){
			gameDog.updateState(MasterAction.TOUCH_ACTION);
		}
		if(v == bath){
			gameDog.updateState(MasterAction.BATH_ACTION);
		}
		else if(v == eat){
			gameDog.updateState(MasterAction.EAT_ACTION);
		}
		else if(v == find){
			gameDog.updateState(MasterAction.FIND_ACTION);
		}
	}
	
}
enum DogState {//表示狀態的列舉類別型
	BATH_STATE,    		    // 洗澡狀態
	COMMON_STATE,   		// 普通狀態
	AWAY_STATE,				// 出走狀態
	EAT_STATE,				// 餵養狀態
	TOUCH_STATE;            // 撫摸狀態
}
enum MasterAction {//表示主人動作的列舉
	BATH_ACTION,		// 洗澡
	TOUCH_ACTION,		// 撫摸
	FIND_ACTION,		// 尋找
	EAT_ACTION,         // 餵養
	ALONE_ACTION;		// 無人搭理
}