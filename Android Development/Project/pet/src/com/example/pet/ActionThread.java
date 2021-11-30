package com.example.pet;
public class ActionThread extends Thread{
	private int sleepSpan = 8000;//睡眠的毫秒數
	boolean flag = true;//循環標籤位
	MainActivity activity;
	public ActionThread(MainActivity activity){
		this.activity = activity;
	}	
	public void run(){//重寫的run方法
		while(flag){//循環
			try{
				Thread.sleep(sleepSpan);//睡眠指定毫秒數
			}
			catch(Exception e ){
				e.printStackTrace();//打印異常信息
			}
			activity.myHandler.sendEmptyMessage(1);//想activity發生handler訊息
		}
	}
}