function create_account(){  
  var n=document.getElementById("id").value;  
  var e=document.getElementById("name").value;  
  var p=document.getElementById("qual").value;  
  var cp=document.getElementById("des").value; 
  var sl=document.getElementById("sal").value;   
  //Code for validation  
          var letters = /^[A-Za-z]+$/;
          var numbers = /^[0-9]+$/;  
          var email_val = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;  
  //other validations required code  
  if(n==''||e==''||p==''||cp==''||sl==''){  
  alert("Enter each details correctly");  
  }  
  else if(!numbers.test(n))  
          {  
              alert('ID is incorrect must contain numbers only');  
          }  
  else if (!letters.test(e))  
          {  
              alert('Name is incorrect must contain characters only');  
          } 
  else if(!numbers.test(sl))  
          {  
              alert('ID is incorrect must contain numbers only');  
          }    
  else{  
  alert("Your account has been created successfully... Redirecting to Confirmation");  
  window.location="c.html";  
  }  
  }