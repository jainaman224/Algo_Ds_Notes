armstrongNumber = (num) -> 
  originalnum = num
  reoriginalnum=num
  
  result=0
  count=0
  while num != 0
    num = parseInt(num / 10)
    count++
   
  while reoriginalnum != 0
    remainder = reoriginalnum % 10
    result += Math.pow(remainder, count)
    reoriginalnum = parseInt(reoriginalnum / 10)
  

  if result == originalnum
    console.log "Yes, it is an armstrong number"
  else
    console.log "It is not an armstrong number"


#call the function to check whether number is armtsrong number or not
#armstrongNumber 1634