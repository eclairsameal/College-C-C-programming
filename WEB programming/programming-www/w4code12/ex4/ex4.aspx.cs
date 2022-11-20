// ex4.aspx.cs
//   The code behind file for ex4.aspx.
//   In an OnLoad handler, it populates the drop down 
//   list created in the associated ASP.NET document. 
//   It also includes a handler for the button, which 
//   produces a message to the client, including the 
//   client's name and the chosen item from the drop 
//   down list
          
using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public class ex4 : System.Web.UI.Page {
  protected DropDownList color;
  protected TextBox name;
  protected Button submit;
  protected Label message;


// OnLoad handler to populate the dropdownlist

  override protected void OnLoad(EventArgs e) {
    if (!IsPostBack) {
      color.Items.Add(new ListItem("blue"));
      color.Items.Add(new ListItem("red"));
      color.Items.Add(new ListItem("green"));
      color.Items.Add(new ListItem("yellow"));
    }
  }

// Handler for the button

  protected void OnClickHandler(object src, EventArgs e) {
    string newMsg = string.Format(
        "Hi {0}, your favorite color is {1}",
        name.Text, color.SelectedItem);
    message.Text = newMsg;
  }
}
