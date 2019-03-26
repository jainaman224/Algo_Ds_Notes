<?php
	/*
	
	Author: Vedant Wakalkar

	PHP Program to sort numbers using Comb Sort. 
	
	*/

	// function to read from the command line
	function read_stdin()
	{
		$fr=fopen("php://stdin","r");   // open our file pointer to read from stdin
		$input = fgets($fr,128);        // read a maximum of 128 characters
		$input = rtrim($input);         // trim any trailing spaces.
		fclose ($fr);                   // close the file handle
		return $input;                  // return the text entered
	}

	function next_gap($gap)
	{
		// Function to find next gap
		// shrink_factor = 1.3 = 13 / 10
		// Shrink gap by shrink factor
		
		$new_gap = ($gap * 10  / 13);
		
		if($new_gap < 1)
		{
			return 1;
		}

		return $new_gap;
	}

	function CombSort($num_arr)
	{
		# Function to Sort array using Comb sort
		
		# Length of input array
		$n = sizeof($num_arr);

		# Initialize swap to keep running while loop for next swapping
		$swapped = 1;

		# Intialize gap
		$gap = $n;

		while ($gap !=1 or $swapped == 1) 
		{
			# Update gap
			$gap = (int)next_gap($gap);
			
			# To check if swapping is performed in this loop
			$swapped = 0;

			# Compare all elements with current gap
			for($i=0;$i<($n-$gap);$i++)
			{
				if($num_arr[$i]>$num_arr[$i+$gap])
				{
					#swapping numbers
					$temp = $num_arr[$i] ;
					$num_arr[$i] = $num_arr[$i+$gap] ;
					$num_arr[$i+$gap] = $temp;
					
					# swapped occured atleast once
					$swapped = 1;
				}
			}
		}
		return ($num_arr);
	}

	// Input space seperated numbers to sort
	echo "Enter numbers : " ;

	// the script will wait here until the user has entered something and hit ENTER
	$num_arr = read_stdin();

	$num_arr = explode(' ',$num_arr);
	
	$num_arr = CombSort($num_arr);
	// Sorted Array.
	echo "Sorted array (By Comb Sort) : ".implode(' ', $num_arr).PHP_EOL;

	/*

	Output:

	Enter numbers :  19 -9 10 -17 8 -8 17 -10 9 -19
	Sorted array (By Comb Sort) : -19 -17 -10 -9 -8 8 9 10 17 19

	*/

?>
