function ArmstrongNum(num : number)
{
    console.log("Enter number : ", num)
    var sum : number = 0
    var n : number = num
    var r : number = 0
    
    while(n>0)
    {
        r = n%10;
        sum += r*r*r;
        n = (n-r)/10; 
   }
    console.log(sum)
    if(num == sum)
        console.log("Armstrong number.")
    else
        console.log("Not an armstrong number.")

}

ArmstrongNum(153)
ArmstrongNum(34)