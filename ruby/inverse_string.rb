# inverse_string.rb - one of my first tries to invert a string in Ruby

# get a string as an input
puts "Please enter a string:"
input = $stdin.gets.chomp

def inverse_string(string)
	string_arr = string.each_char.to_a					# breaking up the string into an array
	inv_string_arr = []									# creating empty array for the inverse string

	for i in 0..string_arr.length-1						# iterarting over the string array
		interim = string_arr.pop						# placing the last value into an interim variable 
		inv_string_arr = inv_string_arr.push(interim)	# pushing from interim variable into inverse string array
	end
	
	inv_string = inv_string_arr.join()					# creating new string out of array
	return inv_string
end		

puts "\nString inversed:"
puts "#{inverse_string(input)}"