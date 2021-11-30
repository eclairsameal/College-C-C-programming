package com.example.pet;
public class GameDog {
	MainActivity activity = null;//activity的物件變數
	private DogState currentState=DogState.COMMON_STATE;//設置寵物的初始當前狀態為普通狀態
	public GameDog(MainActivity activity){
		this.activity = activity;
	}
	public boolean updateState(MasterAction ma){//接收條件，更新狀態的方法
		boolean result=true;
		switch(currentState){
			case BATH_STATE://當前為狀態
			    switch(ma){
			    	case ALONE_ACTION://超過指定時間無人搭理
			    		currentState=DogState.COMMON_STATE;//切換狀態
				    	activity.myImageView.setImageResource(R.drawable.common);//換圖
				    	activity.myTextView.setText("狀態：普通");
			    	break;
			    	case BATH_ACTION:  //洗澡
			    	   currentState=DogState.BATH_STATE;
				       activity.myImageView.setImageResource(R.drawable.bathe);
				       activity.myTextView.setText("狀態：洗澡");
				    break;	
			    	case TOUCH_ACTION://撫摸
			    	   currentState=DogState.TOUCH_STATE;
			    	   activity.myImageView.setImageResource(R.drawable.touch);
			    	   activity.myTextView.setText("狀態：撫摸");
			    	break;
			    	case EAT_ACTION://餵養
				    	   currentState=DogState.EAT_STATE;//切換狀態
				    	   activity.myImageView.setImageResource(R.drawable.eat);
				    	   activity.myTextView.setText("狀態：餵養");
				    	break;
			    	default:
			    	   result=false;//返回false表示狀態切換出錯
			    }			
			break;
			case COMMON_STATE://當前為普通狀態
			    switch(ma){
			    	case ALONE_ACTION://超過指定時間無人搭理
			    	   currentState=DogState.AWAY_STATE;
			    	   activity.myImageView.setImageResource(R.drawable.away);
			    	   activity.myTextView.setText("狀態：出走");
			    	break;
			    	case BATH_ACTION: //洗澡
			    	   currentState=DogState.BATH_STATE;
				       activity.myImageView.setImageResource(R.drawable.bathe);
				       activity.myTextView.setText("狀態：洗澡");
				    break;	
			    	case TOUCH_ACTION://撫摸
			    	   currentState=DogState.TOUCH_STATE;
			    	   activity.myImageView.setImageResource(R.drawable.touch);
			    	   activity.myTextView.setText("狀態：撫摸");
			    	break;
			    	case EAT_ACTION://餵養
				    	   currentState=DogState.EAT_STATE;
				    	   activity.myImageView.setImageResource(R.drawable.eat);
				    	   activity.myTextView.setText("狀態：餵養");
				    	break;
			    	default:
			    	   result=false;//返回false表示狀態切換出錯
			    }			
			break;
			case TOUCH_STATE://當前為普通狀態
			    switch(ma){
			    	case ALONE_ACTION://超過指定時間無人搭理
			    		currentState=DogState.COMMON_STATE;
				    	activity.myImageView.setImageResource(R.drawable.common);
				    	activity.myTextView.setText("狀態：普通");
			    	break;
			    	case BATH_ACTION: //洗澡
			    	   currentState=DogState.BATH_STATE;
				       activity.myImageView.setImageResource(R.drawable.bathe);
				       activity.myTextView.setText("狀態：洗澡");
				    break;	
			    	case TOUCH_ACTION://撫摸
			    	   currentState=DogState.TOUCH_STATE;
			    	   activity.myImageView.setImageResource(R.drawable.touch);
			    	   activity.myTextView.setText("狀態：撫摸");
			    	break;
			    	case EAT_ACTION://餵養
				    	   currentState=DogState.EAT_STATE;
				    	   activity.myImageView.setImageResource(R.drawable.eat);
				    	   activity.myTextView.setText("狀態：餵養");
				    	break;
			    	default:
			    	   result=false;
			    }			
			break;
			case EAT_STATE://當前為狀態
			    switch(ma){
			    	case ALONE_ACTION://超過指定時間無人搭理
			    		currentState=DogState.COMMON_STATE;
				    	activity.myImageView.setImageResource(R.drawable.common);
				    	activity.myTextView.setText("狀態：普通");
			    	break;
			    	case BATH_ACTION: //洗澡
			    	   currentState=DogState.BATH_STATE;
				       activity.myImageView.setImageResource(R.drawable.bathe);
				       activity.myTextView.setText("狀態：洗澡");
				    break;	
			    	case TOUCH_ACTION://撫摸
			    	   currentState=DogState.TOUCH_STATE;
			    	   activity.myImageView.setImageResource(R.drawable.touch);
			    	   activity.myTextView.setText("狀態：撫摸");
			    	break;
			    	case EAT_ACTION://餵養
				    	   currentState=DogState.EAT_STATE;
				    	   activity.myImageView.setImageResource(R.drawable.eat);
				    	   activity.myTextView.setText("狀態：餵養");
				    	break;
			    	default:
			    	   result=false;//返回false表示狀態切換出錯
			    }			
			break;
			case AWAY_STATE://當前為出走狀態
			    switch(ma){
			    	case FIND_ACTION://尋找
			    	   currentState=DogState.COMMON_STATE;
			    	   activity.myImageView.setImageResource(R.drawable.common);
			    	   activity.myTextView.setText("狀態：普通");
			    	break;
			    	default:
			    	   result=false;
			    }			
			break;
		}
		return result;//返回true表示狀態切換成功
	}
}