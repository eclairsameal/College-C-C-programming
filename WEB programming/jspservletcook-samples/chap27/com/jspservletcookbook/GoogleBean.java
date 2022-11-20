package com.jspservletcookbook;           

import com.google.soap.search.*;

public class GoogleBean {

  private GoogleSearch search;
  private GoogleSearchResult googleRes;
  private final static String GOOGLE_KEY = "5W1BWPyzPSyI3rIa5Pt3DtXMatsniSGB";
  
  private String lineSep = "\n";
  
  //Settable bean properties
  private String query;
  private boolean filter;
  private int maxResults;
  private int startRes;
  private boolean safeSearch;
  private String restrict;
  private String langRestrict;
  

  public GoogleBean(){ 
  
      query = "";
	  restrict = "";
	  langRestrict = "";
  
  }
  
  public String structureResult(GoogleSearchResult res){
  
      GoogleSearchResultElement[] elements = res.getResultElements();
	  String url ="";
	  
	  String results = "Estimated total results count: " +
	      res.getEstimatedTotalResultsCount() + lineSep + lineSep;
	  
	  for (int i = 0; i < elements.length; i++){
	  
	    url = elements[i].getURL();
		
	    results += ("Title: " + elements[i].getTitle() + lineSep +
		    "URL: <a href=\"" + url + "\">" + url + "</a>"+ lineSep +
			"Summary: " + elements[i].getSummary() + lineSep +
			"Snippet: " + elements[i].getSnippet() + lineSep + lineSep);
	  }
	  
	  return results;

 }
  
  public String getSearchResults() throws GoogleSearchFault {
  
      search = new GoogleSearch();
	  
	  search.setKey(GOOGLE_KEY);
	  
	  search.setFilter(filter);
	  
	  if(restrict.length() > 0)
	      search.setRestrict(restrict);
		  
	  search.setQueryString(query);
	  
	  googleRes = search.doSearch();
	  
	  return structureResult(googleRes);
	  
  }
  
  public void setLineSep(String lineSep){
  
      this.lineSep=lineSep;
  }
  
   public String getLineSep(){
  
      return lineSep;
  }

  public void setQuery(String query){
  
      this.query = query;
  
  }
  
 public String getQuery(){
  
      return query;
  }
  
  public void setRestrict(String query){
  
      this.restrict = restrict;
  
  }
  
   public String getRestrict(){
  
      return restrict;
  }
  
  public void setLangRestrict(String query){
  
  this.langRestrict = langRestrict;
  
  }
  
  public String getLangRestrict(){
  
      return langRestrict;
  }
  
  public void setFilter(boolean filter){
  
      this.filter = filter;
  
  }
  
  public boolean getFilter(){
  
      return filter;
  }
  
   public void setSafeSearch(boolean filter){
  
      this.safeSearch = safeSearch;
  
  }
  
  public boolean getSafeSearch(){
  
      return safeSearch;
  }
  
  public void setMaxResults(int maxResults){
  
      this.maxResults = maxResults;
  
  }
  
  public int getMaxResults(){
  
      return maxResults;
  
  }
  
  public void setStartRes(int startRes){
  
      this.startRes = startRes;
  
  }

  public int getStartRes(){
  
      return startRes;
  
   }
   
   public void release(){
   
       search = null;
	   googleRes = null;
   }
   
   
  
}
