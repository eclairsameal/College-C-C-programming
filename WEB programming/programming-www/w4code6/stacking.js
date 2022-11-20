// stacking.js
//   Illustrates dynamic stacking of images

var top = "C172";

// The event handler function to move teh given element
//  to the top of the display stack

function toTop(newTop) {

// Set the two dom addresses, one for the old top 
//  element and one for the new top element 

  domTop = document.getElementById(top).style;
  domNew = document.getElementById(newTop).style;

// Set the zIndex properties of the two elements, and
//  reset top to the new top

  domTop.zIndex = "0";
  domNew.zIndex = "10";
  top = newTop;
}
