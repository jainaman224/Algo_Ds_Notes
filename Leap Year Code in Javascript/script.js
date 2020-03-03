function check_leapyear(){
    //define variables
    var year;

    //get the entered year from text box
    year = document.getElementById("year").value;

    //three conditions to find out the leap year
    if( (0 == year % 4) && (0 != year % 100) || (0 == year % 400) )
    {
        alert(year+" is a leap year");
    }
    else
    {
        alert(year+" is not a leap year");
    }
}