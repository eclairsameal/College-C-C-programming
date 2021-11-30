package app.hw3_2;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends Activity {

  int cards[] = {R.drawable.club_1, R.drawable.club_king, R.drawable.club_queen, R.drawable.club_jack, R.drawable.club_10, 
		     R.drawable.club_9, R.drawable.club_8, R.drawable.club_7, R.drawable.club_6, R.drawable.club_5,
		     R.drawable.club_4, R.drawable.club_3, R.drawable.club_2,
		    
		     R.drawable.diamond_1, R.drawable.diamond_king, R.drawable.diamond_queen, R.drawable.diamond_jack, R.drawable.diamond_10, 
		     R.drawable.diamond_9, R.drawable.diamond_8, R.drawable.diamond_7, R.drawable.diamond_6, R.drawable.diamond_5,
		     R.drawable.diamond_4, R.drawable.diamond_3, R.drawable.diamond_2,
		     
		     R.drawable.heart_1, R.drawable.heart_king, R.drawable.heart_queen, R.drawable.heart_jack, R.drawable.heart_10, 
		     R.drawable.heart_9, R.drawable.heart_8, R.drawable.heart_7, R.drawable.heart_6, R.drawable.heart_5,
		     R.drawable.heart_4, R.drawable.heart_3, R.drawable.heart_2,
		     
		     R.drawable.spade_1, R.drawable.spade_king, R.drawable.spade_queen, R.drawable.spade_jack, R.drawable.spade_10, 
		     R.drawable.spade_9, R.drawable.spade_8, R.drawable.spade_7, R.drawable.spade_6, R.drawable.spade_5,
		     R.drawable.spade_4, R.drawable.spade_3, R.drawable.spade_2};
  
	boolean csrbbool[] = new boolean[52]; // 52
	boolean computerbool[] = new boolean[5]; 
	//boolean playerbbool[] = new boolean[5];
	ImageButton imagebutton[] = new ImageButton[5];
	ImageView imageview[] = new ImageView[5];
	int computer_point = 0, play_point = 0, game_count = 0;
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		for(int i = 0; i < 52; i++){csrbbool[i] = false;}
		for(int i = 0; i < 5; i++){computerbool[i] = false;}
		//for(int i = 0; i < 5; i++){playerbbool[i] = false;}
	}

	public void Click_0(View view) {
	  int computer_r = (int) (Math.random() * 52);  
	  int play_r = (int) (Math.random() * 52);
	  while(csrbbool[computer_r] == true){computer_r = (int) (Math.random() * 52);}
	  while(csrbbool[play_r] == true){play_r = (int) (Math.random() * 52);}   
	  csrbbool[computer_r] = true;
	  csrbbool[play_r] = true;
	    // 亂數選牌
	  imagebutton[0] = (ImageButton) findViewById (R.id.imageButton1);
	  imagebutton[0].setImageResource(cards[play_r]);
	  
	  int computercard = (int) (Math.random() * 5); // 電腦選的位置
	  while(computerbool[computercard] == true){computercard = (int) (Math.random() * 5);}
	  computerbool[computercard] = true;
	  
	  switch(computercard){
	    case 0: imageview[0] = (ImageView)findViewById(R.id.imageView1);
	            imageview[0].setImageResource(cards[computer_r]);
	            computerbool[0] = true;
	            break;
	    case 1: imageview[1] = (ImageView)findViewById(R.id.imageView2);
	            imageview[1].setImageResource(cards[computer_r]);
                computerbool[1] = true;
	            break;
	    case 2: imageview[2] = (ImageView)findViewById(R.id.imageView3);
	            imageview[2].setImageResource(cards[computer_r]);
                computerbool[2] = true;
	            break;
	    case 3: imageview[3] = (ImageView)findViewById(R.id.imageView4); 
	            imageview[3].setImageResource(cards[computer_r]);
                computerbool[3] = true;
	            break;
	    case 4: imageview[4] = (ImageView)findViewById(R.id.imageView5);
	            imageview[4].setImageResource(cards[computer_r]);
                computerbool[4] = true;
	            break;
	  }
	  
	  // 比較結果計算分數
	  TextView outpoint = (TextView)findViewById(R.id.points);
	  int points = 0, c = 0, p = 0;
	  c = (computer_r + 1) % 13;
	  p = (play_r + 1) % 13;
	  
	  if(c==1){points+=40;}
	  else if(c==2){points+=30;}
	  else if(c==3){points+=20;}
	  else if(c==4){points+=10;}
	  else{points+=(15 - c);} 
		  		  
	  if(p==1){points+=40;} 
	  else if(p==2){points+=30;}
	  else if(p==3){points+=20;}
	  else if(p==4){points+=10;}
	  else{points+=(15 - p);}  
	  
	  if(c == 0){c = 13;}
	  if(p == 0){p = 13;}
	  String str = "";
	  
	  if(c > p){
		str = "The computer wins "+points+" points."; 
		outpoint.setText(str);
		computer_point+=points;
		game_count++;		    
	  }
	  
	  else if(c < p){
		str = "The player wins "+points+" points."; 
		outpoint.setText(str);
		play_point+=points;
		game_count++;		    
	  }	
	  else if(c == p){
	    if(computer_r > play_r){
		  str = "The computer wins "+points+" points."; 
		  outpoint.setText(str);
		  computer_point+=points;
		  game_count++;
	    }
	    if(computer_r < play_r){
		  str = "The player wins "+points+" points."; 
		  outpoint.setText(str);
		  play_point+=points;
		  game_count++;
	    }		    
	  }
	  
	  TextView output;
	  if(game_count == 5){
		output = (TextView)findViewById(R.id.textView3);  
		str = "The player wins "+play_point+" points. ";
		output.setText(str);
		output = (TextView)findViewById(R.id.textView4); 
		str = "The computer wins "+computer_point+" points. ";
		output.setText(str);
		output = (TextView)findViewById(R.id.textView5); 
		if(play_point>computer_point){
		  str = "The player wins the game.";
		  output.setText(str);
		}
		else{
		  str = "The computer wins the game.";
		  output.setText(str);			
		}  
	  }
	}
	public void Click_1(View view) {
		  int computer_r = (int) (Math.random() * 52);  
		  int play_r = (int) (Math.random() * 52);
		  while(csrbbool[computer_r] == true){computer_r = (int) (Math.random() * 52);}
		  while(csrbbool[play_r] == true){play_r = (int) (Math.random() * 52);}   
		  csrbbool[computer_r] = true;
		  csrbbool[play_r] = true;
		    // 亂數選牌
		  imagebutton[1] = (ImageButton) findViewById (R.id.imageButton2);
		  imagebutton[1].setImageResource(cards[play_r]);
		  
		  int computercard = (int) (Math.random() * 5); // 電腦選的位置
		  while(computerbool[computercard] == true){computercard = (int) (Math.random() * 5);}
		  computerbool[computercard] = true;
		  
		  switch(computercard){
		    case 0: imageview[0] = (ImageView)findViewById(R.id.imageView1);
		            imageview[0].setImageResource(cards[computer_r]);
		            computerbool[0] = true;
		            break;
		    case 1: imageview[1] = (ImageView)findViewById(R.id.imageView2);
		            imageview[1].setImageResource(cards[computer_r]);
	                computerbool[1] = true;
		            break;
		    case 2: imageview[2] = (ImageView)findViewById(R.id.imageView3);
		            imageview[2].setImageResource(cards[computer_r]);
	                computerbool[2] = true;
		            break;
		    case 3: imageview[3] = (ImageView)findViewById(R.id.imageView4); 
		            imageview[3].setImageResource(cards[computer_r]);
	                computerbool[3] = true;
		            break;
		    case 4: imageview[4] = (ImageView)findViewById(R.id.imageView5);
		            imageview[4].setImageResource(cards[computer_r]);
	                computerbool[4] = true;
		            break;
		  }
		  
		  // 比較結果計算分數
		  //computer_r  play_r
		  TextView outpoint = (TextView)findViewById(R.id.points);
		  int points = 0, c = 0, p = 0;
		  c = (computer_r + 1) % 13;
		  p = (play_r + 1) % 13;
		  
		  if(c==1){points+=40;}
		  else if(c==2){points+=30;}
		  else if(c==3){points+=20;}
		  else if(c==4){points+=10;}
		  else{points+=(15 - c);} 
			  		  
		  if(p==1){points+=40;} 
		  else if(p==2){points+=30;}
		  else if(p==3){points+=20;}
		  else if(p==4){points+=10;}
		  else{points+=(15 - p);}  
		  String str = ""; 
		  if(c == 0){c = 13;}
		  if(p == 0){p = 13;}
		  
		  if(c > p){
			str = "The computer wins "+points+" points."; 
			outpoint.setText(str);
			computer_point+=points;
			game_count++;		    
		  }
		  
		  else if(c < p){
			str = "The player wins "+points+" points."; 
			outpoint.setText(str);
			play_point+=points;
			game_count++;		    
		  }	
		  else if(c == p){
		    if(computer_r > play_r){
			  str = "The computer wins "+points+" points."; 
			  outpoint.setText(str);
			  computer_point+=points;
			  game_count++;
		    }
		    if(computer_r < play_r){
			  str = "The player wins "+points+" points."; 
			  outpoint.setText(str);
			  play_point+=points;
			  game_count++;
		    }		    
		  }
		  
		  TextView output;
		  if(game_count == 5){
			output = (TextView)findViewById(R.id.textView3);  
			str = "The player wins "+play_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView4); 
			str = "The computer wins "+computer_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView5); 		
			if(play_point>computer_point){
			  str = "The player wins the game.";
			  output.setText(str);
			}
			else{
			  str = "The computer wins the game.";
			  output.setText(str);			
			}  
		  }
		}
	public void Click_2(View view) {
		  int computer_r = (int) (Math.random() * 52);  
		  int play_r = (int) (Math.random() * 52);
		  while(csrbbool[computer_r] == true){computer_r = (int) (Math.random() * 52);}
		  while(csrbbool[play_r] == true){play_r = (int) (Math.random() * 52);}   
		  csrbbool[computer_r] = true;
		  csrbbool[play_r] = true;
		    // 亂數選牌
		  imagebutton[2] = (ImageButton) findViewById (R.id.imageButton3);
		  imagebutton[2].setImageResource(cards[play_r]);
		  
		  int computercard = (int) (Math.random() * 5); // 電腦選的位置
		  while(computerbool[computercard] == true){computercard = (int) (Math.random() * 5);}
		  computerbool[computercard] = true;
		  
		  switch(computercard){
		    case 0: imageview[0] = (ImageView)findViewById(R.id.imageView1);
		            imageview[0].setImageResource(cards[computer_r]);
		            computerbool[0] = true;
		            break;
		    case 1: imageview[1] = (ImageView)findViewById(R.id.imageView2);
		            imageview[1].setImageResource(cards[computer_r]);
	                computerbool[1] = true;
		            break;
		    case 2: imageview[2] = (ImageView)findViewById(R.id.imageView3);
		            imageview[2].setImageResource(cards[computer_r]);
	                computerbool[2] = true;
		            break;
		    case 3: imageview[3] = (ImageView)findViewById(R.id.imageView4); 
		            imageview[3].setImageResource(cards[computer_r]);
	                computerbool[3] = true;
		            break;
		    case 4: imageview[4] = (ImageView)findViewById(R.id.imageView5);
		            imageview[4].setImageResource(cards[computer_r]);
	                computerbool[4] = true;
		            break;
		  }
		  
		  // 比較結果計算分數
		  //computer_r  play_r
		  TextView outpoint = (TextView)findViewById(R.id.points);
		  int points = 0, c = 0, p = 0;
		  c = (computer_r + 1) % 13;
		  p = (play_r + 1) % 13;
		  
		  if(c==1){points+=40;}
		  else if(c==2){points+=30;}
		  else if(c==3){points+=20;}
		  else if(c==4){points+=10;}
		  else{points+=(15 - c);} 
			  		  
		  if(p==1){points+=40;} 
		  else if(p==2){points+=30;}
		  else if(p==3){points+=20;}
		  else if(p==4){points+=10;}
		  else{points+=(15 - p);}  
		  if(c == 0){c = 13;}
		  if(p == 0){p = 13;}
		  String str = "";
		  
		  if(c > p){
			str = "The computer wins "+points+" points."; 
			outpoint.setText(str);
			computer_point+=points;
			game_count++;		    
		  }
		  
		  else if(c < p){
			str = "The player wins "+points+" points."; 
			outpoint.setText(str);
			play_point+=points;
			game_count++;		    
		  }	
		  else if(c == p){
		    if(computer_r > play_r){
			  str = "The computer wins "+points+" points."; 
			  outpoint.setText(str);
			  computer_point+=points;
			  game_count++;
		    }
		    if(computer_r < play_r){
			  str = "The player wins "+points+" points."; 
			  outpoint.setText(str);
			  play_point+=points;
			  game_count++;
		    }		    
		  }
		  
		  TextView output;
		  if(game_count == 5){
			output = (TextView)findViewById(R.id.textView3);  
			str = "The player wins "+play_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView4); 
			str = "The computer wins "+computer_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView5); 	
			if(play_point>computer_point){
			  str = "The player wins the game.";
			  output.setText(str);
			}
			else{
			  str = "The computer wins the game.";
			  output.setText(str);			
			}  
		  }
		}
	public void Click_3(View view) {
		  int computer_r = (int) (Math.random() * 52);  
		  int play_r = (int) (Math.random() * 52);
		  while(csrbbool[computer_r] == true){computer_r = (int) (Math.random() * 52);}
		  while(csrbbool[play_r] == true){play_r = (int) (Math.random() * 52);}   
		  csrbbool[computer_r] = true;
		  csrbbool[play_r] = true;
		    // 亂數選牌
		  imagebutton[3] = (ImageButton) findViewById (R.id.imageButton4);
		  imagebutton[3].setImageResource(cards[play_r]);
		  
		  int computercard = (int) (Math.random() * 5); // 電腦選的位置
		  while(computerbool[computercard] == true){computercard = (int) (Math.random() * 5);}
		  computerbool[computercard] = true;
		  
		  switch(computercard){
		    case 0: imageview[0] = (ImageView)findViewById(R.id.imageView1);
		            imageview[0].setImageResource(cards[computer_r]);
		            computerbool[0] = true;
		            break;
		    case 1: imageview[1] = (ImageView)findViewById(R.id.imageView2);
		            imageview[1].setImageResource(cards[computer_r]);
	                computerbool[1] = true;
		            break;
		    case 2: imageview[2] = (ImageView)findViewById(R.id.imageView3);
		            imageview[2].setImageResource(cards[computer_r]);
	                computerbool[2] = true;
		            break;
		    case 3: imageview[3] = (ImageView)findViewById(R.id.imageView4); 
		            imageview[3].setImageResource(cards[computer_r]);
	                computerbool[3] = true;
		            break;
		    case 4: imageview[4] = (ImageView)findViewById(R.id.imageView5);
		            imageview[4].setImageResource(cards[computer_r]);
	                computerbool[4] = true;
		            break;
		  }
		  
		  // 比較結果計算分數
		  //computer_r  play_r
		  TextView outpoint = (TextView)findViewById(R.id.points);
		  int points = 0, c = 0, p = 0;
		  c = (computer_r + 1) % 13;
		  p = (play_r + 1) % 13;
		  
		  if(c==1){points+=40;}
		  else if(c==2){points+=30;}
		  else if(c==3){points+=20;}
		  else if(c==4){points+=10;}
		  else{points+=(15 - c);} 
			  		  
		  if(p==1){points+=40;} 
		  else if(p==2){points+=30;}
		  else if(p==3){points+=20;}
		  else if(p==4){points+=10;}
		  else{points+=(15 - p);}  
		  if(c == 0){c = 13;}
		  if(p == 0){p = 13;}
		  String str = "";
		  
		  if(c > p){
			str = "The computer wins "+points+" points."; 
			outpoint.setText(str);
			computer_point+=points;
			game_count++;		    
		  }
		  
		  else if(c < p){
			str = "The player wins "+points+" points."; 
			outpoint.setText(str);
			play_point+=points;
			game_count++;		    
		  }	
		  else if(c == p){
		    if(computer_r > play_r){
			  str = "The computer wins "+points+" points."; 
			  outpoint.setText(str);
			  computer_point+=points;
			  game_count++;
		    }
		    if(computer_r < play_r){
			  str = "The player wins "+points+" points."; 
			  outpoint.setText(str);
			  play_point+=points;
			  game_count++;
		    }		    
		  }
		  
		  TextView output;
		  if(game_count == 5){
			output = (TextView)findViewById(R.id.textView3);  
			str = "The player wins "+play_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView4); 
			str = "The computer wins "+computer_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView5); 		
			if(play_point>computer_point){
			  str = "The player wins the game.";
			  output.setText(str);
			}
			else{
			  str = "The computer wins the game.";
			  output.setText(str);			
			}  
		  }
		}
	public void Click_4(View view) {
		  int computer_r = (int) (Math.random() * 52);  
		  int play_r = (int) (Math.random() * 52);
		  while(csrbbool[computer_r] == true){computer_r = (int) (Math.random() * 52);}
		  while(csrbbool[play_r] == true){play_r = (int) (Math.random() * 52);}   
		  csrbbool[computer_r] = true;
		  csrbbool[play_r] = true;
		    // 亂數選牌
		  imagebutton[4] = (ImageButton) findViewById (R.id.imageButton5);
		  imagebutton[4].setImageResource(cards[play_r]);
		  
		  int computercard = (int) (Math.random() * 5); // 電腦選的位置
		  while(computerbool[computercard] == true){computercard = (int) (Math.random() * 5);}
		  computerbool[computercard] = true;
		  
		  switch(computercard){
		    case 0: imageview[0] = (ImageView)findViewById(R.id.imageView1);
		            imageview[0].setImageResource(cards[computer_r]);
		            computerbool[0] = true;
		            break;
		    case 1: imageview[1] = (ImageView)findViewById(R.id.imageView2);
		            imageview[1].setImageResource(cards[computer_r]);
	                computerbool[1] = true;
		            break;
		    case 2: imageview[2] = (ImageView)findViewById(R.id.imageView3);
		            imageview[2].setImageResource(cards[computer_r]);
	                computerbool[2] = true;
		            break;
		    case 3: imageview[3] = (ImageView)findViewById(R.id.imageView4); 
		            imageview[3].setImageResource(cards[computer_r]);
	                computerbool[3] = true;
		            break;
		    case 4: imageview[4] = (ImageView)findViewById(R.id.imageView5);
		            imageview[4].setImageResource(cards[computer_r]);
	                computerbool[4] = true;
		            break;
		  }
		  
		  // 比較結果計算分數
		  //computer_r  play_r
		  TextView outpoint = (TextView)findViewById(R.id.points);
		  int points = 0, c = 0, p = 0;
		  c = (computer_r + 1) % 13;
		  p = (play_r + 1) % 13;
		  
		  if(c==1){points+=40;}
		  else if(c==2){points+=30;}
		  else if(c==3){points+=20;}
		  else if(c==4){points+=10;}
		  else{points+=(15 - c);} 
			  		  
		  if(p==1){points+=40;} 
		  else if(p==2){points+=30;}
		  else if(p==3){points+=20;}
		  else if(p==4){points+=10;}
		  else{points+=(15 - p);}  
		  if(c == 0){c = 13;}
		  if(p == 0){p = 13;}
		  String str = "";
		  
		  if(c > p){
			str = "The computer wins "+points+" points."; 
			outpoint.setText(str);
			computer_point+=points;
			game_count++;		    
		  }
		  
		  else if(c < p){
			str = "The player wins "+points+" points."; 
			outpoint.setText(str);
			play_point+=points;
			game_count++;		    
		  }	
		  else if(c == p){
		    if(computer_r > play_r){
			  str = "The computer wins "+points+" points."; 
			  outpoint.setText(str);
			  computer_point+=points;
			  game_count++;
		    }
		    if(computer_r < play_r){
			  str = "The player wins "+points+" points."; 
			  outpoint.setText(str);
			  play_point+=points;
			  game_count++;
		    }		    
		  }
		  
		  TextView output;
		  if(game_count == 5){
			output = (TextView)findViewById(R.id.textView3);  
			str = "The player wins "+play_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView4); 
			str = "The computer wins "+computer_point+" points. ";
			output.setText(str);
			output = (TextView)findViewById(R.id.textView5); 		
			if(play_point>computer_point){
			  str = "The player wins the game.";
			  output.setText(str);
			}
			else{
			  str = "The computer wins the game.";
			  output.setText(str);			
			}  
		  }
		}
}
