package com.jspservletcookbook;

import javax.ejb.*;

import java.util.Map;
import java.util.HashMap;
/**
 * @ejbgen:session
 *   ejb-name =  AbbreviationEjb
 *   type = Stateless
 *
 * @ejbgen:jndi-name
 *   remote =  AbbrevHome
 *   local =  AbbrevLocalHome
 *
 */

public class AbbrevBean implements SessionBean{


	private SessionContext context;
	private Map abbrevMap;
	
	
	public AbbrevBean(){ 
	
	abbrevMap = new HashMap();
	
	abbrevMap.put("ALABAMA","AL");
	abbrevMap.put("ALASKA","AK");
	abbrevMap.put("AMERICAN SAMOA","AS");
	abbrevMap.put("ARIZONA","AZ");
	abbrevMap.put("ARKANSAS","AR");
	abbrevMap.put("CALIFORNIA","CA");
	abbrevMap.put("COLORADO","CO");
	abbrevMap.put("CONNECTICUTT","CT");
	
	abbrevMap.put("DELAWARE","DE");
	abbrevMap.put("DISTRICT OF COLUMBIA","DC");
	abbrevMap.put("FEDERATED STATES OF MICRONESIA","FM");
	abbrevMap.put("FLORIDA","FL");
	abbrevMap.put("GEORGIA","GA");
	abbrevMap.put("GUAM","GU");
	abbrevMap.put("HAWAII","HI");
	abbrevMap.put("IDAHO","ID");
	
	abbrevMap.put("ILLINOIS","IL");
	abbrevMap.put("INDIANA","IN");
	abbrevMap.put("IOWA","IA");
	abbrevMap.put("KANSAS","KS");
	abbrevMap.put("KENTUCKY","KY");
	abbrevMap.put("LOUISIANA","LA");
	
	abbrevMap.put("MAINE","ME");
	abbrevMap.put("MARSHALL ISLANDS","MH");
	abbrevMap.put("MARYLAND","MD");
	abbrevMap.put("MASSACHUSETTS","MA");
	abbrevMap.put("MICHIGAN","MI");
	abbrevMap.put("MINNESOTA","MN");
	
	abbrevMap.put("MISSISSIPPI","MS");
	abbrevMap.put("MISSOURI","MO");
	abbrevMap.put("MONTANA","MT");
	abbrevMap.put("NEBRASKA","NE");
	abbrevMap.put("NEVADA","NV");
	abbrevMap.put("NEW HAMPSHIRE","NH");
	
	abbrevMap.put("NEW JERSEY","Nj");
	abbrevMap.put("NEW MEXICO","NM");
	abbrevMap.put("NEW YORK","NY");
	abbrevMap.put("NORTH CAROLINA","NC");
	abbrevMap.put("NORTH DAKOTA","ND");
	abbrevMap.put("NORTHERN MARIANA ISLANDS","MP");
	
	abbrevMap.put("OKLAHOMA","OK");
	abbrevMap.put("OREGON","OR");
	abbrevMap.put("PALAU","PW");
	abbrevMap.put("PENNSYLVANIA","PA");
	abbrevMap.put("PUERTO RICO","PR");
	abbrevMap.put("RHODE ISLAND","RI");
	abbrevMap.put("SOUTH CAROLINA","SC");
	abbrevMap.put("SOUTH DAKOTA","SD");
	
	abbrevMap.put("TENNESSEE","TN");
	abbrevMap.put("TEXAS","TX");
	abbrevMap.put("UTAH","UT");
	abbrevMap.put("VERMONT","VT");
	abbrevMap.put("VIRGIN ISLANDS","VI");
	abbrevMap.put("VIRGINIA","VA");
	abbrevMap.put("WASHINGTON","WA");
   abbrevMap.put("WEST VIRGINIA","WV");
   
		abbrevMap.put("WISCONSIN","WI");
		abbrevMap.put("WYOMING","WY");

	
	}
	
	public void setSessionContext (SessionContext ctx) throws EJBException {
	
	    context = ctx;
	}


	public Map getAbbrevMap(){
	
	return abbrevMap;
	
	}
	
	public String getAbbreviation(String state){
	
	return (String) abbrevMap.get(state);
	
	
	}
	
	public void ejbCreate(){
	
	prt( "ejbCreate called.");
	
	}
	
	
	public void ejbActivate(){
	
	prt( "ejbActivate called.");
	
	}
	
	public void ejbPassivate(){
	
	prt( "ejbPassivate called.");
	
	}
	
    private void prt(Object message){
	
		System.out.println(message);
	}

	public void ejbRemove() {
	
	prt( "ejbRemove called.");
	
	}

  
}