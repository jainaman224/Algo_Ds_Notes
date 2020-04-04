## Tower Of Hanoi In Ruby

## Recursive Function
def tower(disk, source, auxilary, destination)
    if disk == 1
        puts "Disk #{disk} moves from #{source} to #{destination}"
        return
    end

    tower(disk - 1, source, destination, auxilary)
    puts "Disk #{disk} moves from #{source} to #{destination}"
    tower(disk - 1, auxilary, source, destination)
    nil

end

## Taking User Input For Number Of disks
puts "Enter the number of disks: "
disk = gets.to_i
puts

## Fucntion Call
tower(disk, 'source', 'auxiliary', 'destination')

=begin

Enter the number of disks: 3

Disk 1 moves from Source to Destination
Disk 2 moves from Source to Auxiliary
Disk 1 moves from Destination to Auxiliary
Disk 3 moves from Source to Destination
Disk 1 moves from Auxiliary to Source
Disk 2 moves from Auxiliary to Destination
Disk 1 moves from Source to Destination

=end
