function  leapyear() {
    var year;

    year = document.getElementById("year").value;

    if((0 == year % 4) && (0 != year % 100) || (0 == year % 400)){
        alert(year + " is a leap year");
    }
    else {
        alert(year + " is not a leap year");
    }
}

//Sample IP = 2020
//Sample OP = 2020 is a leap year