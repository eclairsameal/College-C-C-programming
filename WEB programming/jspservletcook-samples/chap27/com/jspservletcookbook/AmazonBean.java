package com.jspservletcookbook;

import java.net.URL;           

import com.amazon.soap.axis.*;

public class AmazonBean {

  private final static String AMAZON_KEY = "DCJEAVDSXVPUD";
  private final static String END_POINT = "http://soap.amazon.com/onca/soap";
   private final static String AMAZON_TAG = "webservices-20";
  
  private URL endpointUrl;
  
  private String lineSep = "\n";
  private String totalResults;
  private String keyword;
  private String page;
  private String type;
  private String mode;
  

  public AmazonBean(){  }
  
  public static void main(String[] args) throws Exception{
  
      AmazonBean bean = new AmazonBean();
      bean.setKeyword("Lance%20Armstrong");
      bean.setType("heavy");
      bean.setMode("books");
      bean.setPage("1");
      
      System.out.println( bean.getSearchResults() );
  }
  
  public String structureResult(ProductInfo info){
      
      Details[] details = info.getDetails();
      
      String results = "";
	  
      String[] authors = null;
      String usedP = null;
      String rank = null;
      
      for (int i = 0; i < details.length; i++){
      
	      
	  if(mode != null && mode.equals("books")){
          authors = details[i].getAuthors(); }
          
          results += "<strong>"+(i+1)+". Product name:</strong> " + details[i].getProductName() + lineSep;
          
		  if(mode != null && mode.equals("books")){
                for (int j = 0; j < authors.length; j++)
                    results += "Author name "+(j+1)+": " + authors[j] + lineSep;
		  }

          usedP = details[i].getUsedPrice();
          rank = details[i].getSalesRank();
                    
          results += "Sales rank: " + (rank == null ? "N/A" : rank) + lineSep +
          "List price: " + details[i].getListPrice() + lineSep +
          "Our price: " + details[i].getOurPrice() + lineSep + 
          "Used price: " + (usedP == null ? "N/A" : usedP) + lineSep + lineSep;  
      
      }
      
      return results;

 }
  
  public String getSearchResults() throws Exception{
  
     endpointUrl = new URL(END_POINT);

    AmazonSearchService  webService = new AmazonSearchServiceLocator();
      
      AmazonSearchPort port = webService.getAmazonSearchPort(endpointUrl);
      
      KeywordRequest request = getKeywordRequest();
      
      ProductInfo prodInfo = port.keywordSearchRequest(request);
      
      setTotalResults( prodInfo.getTotalResults() );
      
      return structureResult(prodInfo);
      
  }
  
  public void setLineSep(String lineSep){
  
      this.lineSep=lineSep;
  }
  
   public String getLineSep(){
  
      return lineSep;
  }
  
  public KeywordRequest getKeywordRequest(){
  
      KeywordRequest request = new KeywordRequest();
      request.setKeyword(keyword);
      request.setMode(mode);
      request.setPage(page);
      request.setType(type);
      
      request.setDevtag(AMAZON_KEY);
      
      request.setTag(AMAZON_TAG);
      
      return request;
  
  }

  public void setKeyword(String keyword){
  
      this.keyword = keyword;
  
  }
  
 public String getKeyword(){
  
      return keyword;
  }
  
  public void setMode(String mode){
  
      this.mode = mode;
  
  }
  
   public String getMode(){
  
      return mode;
  }
  
 public void setPage(String page){
  
  this.page = page;
  
  }
  
  public String getPage(){
  
      return page;
  }

   public void setType(String type){
  
  this.type = type;
  
  }
  
  public String getType(){
  
      return type;
  }
  
  public void setTotalResults(String results){
  
  totalResults = results;
  
  }
  
  public String getTotalResults(){
  
      return totalResults;
  }
   
   public void release(){
   
   }
   
   
  
}
