const mongoose = require('mongoose'); 
var Details = mongoose.model('Details',{ 
    name : {type : String},
    email : {type:String,unique : true},
    product : {type : String},
    category: {type: String},
    totalval: {type: String},
    inideposit: {type: String},
    remainingval: {type: String},
});
module.exports = Details;