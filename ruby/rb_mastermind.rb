# rb_mastermind.rb - A simple implementation of the popular game mastermind in Ruby

def rules
	puts "In this game you have to crack a randomly generated code using logical deduction."
	puts "A code is made out of 3 integers from 0 to 5 (in Easy) or 4 integers from 0 to 7 (in Normal)."
	puts "The game starts with a code generated and you have to enter a set of numbers which you think could be the code."
	puts "After your selection you will be given a set of symbols to hint at the answer:"
	puts "\t! means one of your entered numbers are in the code and at the right place."
	puts "\t? means one of your entered numbers are in the code but not at the right place."
	puts "\tX means one of your entered numbers are not in the code."
	puts "Keep in mind that the position of the symbols are not related to the position of your entered numbers."
	puts "For example:"
	puts "The game starts with the code : [1, 2, 3]"
	puts "You first enter: 2 4 3"
	puts "And the symbols would be: [!, ?, X]"
	$stdin.gets
	master_mind_start
end

def master_mind_start
	while true
		puts "\nWelcome to Mastermind, the classic logic game."
		puts "Enter --rules to see the rules."
		puts "Enter --start to start the game."	
		puts "Enter --quit to exit the game."
		start = $stdin.gets.chomp

		if start == "--rules"
			rules
		elsif start == "--start"
			puts "Which difficulty do you choose?"
			puts "--easy"
			puts "\tCode contains 3 unique integers from 0 to 2, possible numbers are from 0 to 5"
			puts "\tUnlimited attempts"
			puts "--normal"
			puts "\tCode contains 4 unique integers from 0 to 3, possible numbers are from 0 to 7"
			puts "\tMax. 10 attempts"
		 	start2 = $stdin.gets.chomp

		 	if start2 =="--easy"
		 		master_mind_easy
		 	elsif start2 == "--normal"
		 		master_mind_normal	
		 	else 
		 		start == "--start"	
		 	end

		 elsif start == "--quit"
		 	puts "Thanks for playing!"
		 	exit(0)
		 else 
		 	puts "I don't know what that means."	
		end

	end	
end	

def master_mind_easy
	# This creates an array with 3 unique numbers from 0 to 5
	code = []
	while code.length < 3 do 
		random = rand(6)
		unless code.include?(random)
			code << random
		end
	end
	
	puts "#{code}"
	
	puts "Please enter three integers from 0 to 5 in the following format: 1 2 3"
	check = []
	attempts = 1
	until check == ["!", "!", "!"]
		# Creating an array to with an user input
		print "Attempt ##{attempts} > "
		input = $stdin.gets

		enter = input.split(" ")
		enter.map! { |i| i.to_i }
	
		# Check enter against code 3 times
		# 1) if enter at position equals code at position -> push ! into check[]
		# 2) if enter at poisition is found in code but not at same poisition -> push ? into check[]
		# 3) if enter at poisition is not found in code at all -> push 0 into check[]
	
		for i in 0..2
			if enter[i] == code[i]
				check << "!"
			elsif code.include?(enter[i]) && (enter[i] != code[i])
				check << "?"
			else
				check << "X"						
			end
		end	
			
		check.sort!
		print "#{enter} --> #{check}\n"

		attempts += 1

		# Breaking out of the loop
		unless check == ["!", "!", "!"]
	 		check = []
		 end 

	end	
	win(code, attempts-1)
end	

def master_mind_normal
	code = []
	while code.length < 4 do 
		random = rand(8)
		unless code.include?(random)
			code << random
		end
	end
	
	puts "#{code}"
	
	puts "Please enter three integers from 0 to 7 in the following format: 1 2 3 4"
	check = []
	attempts = 9

	until check == ["!", "!", "!", "!"]
		print "Attempt ##{attempts} > "
		input = $stdin.gets

		enter = input.split(" ")
		enter.map! { |i| i.to_i }
	
		for i in 0..3
			if enter[i] == code[i]
				check << "!"
			elsif code.include?(enter[i]) && (enter[i] != code[i])
				check << "?"
			else
				check << "X"						
			end
		end	
			
		check.sort!
		print "#{enter} --> #{check}\n"

		unless check == ["!", "!", "!", "!"]
	 		check = []
		 end 

		attempts += 1
		if attempts == 12
			lose(code)
		end

	end
	win(code, attempts-1)
end

def lose(code)
	puts "Sorry, you lost! The code was #{code}."
	play_again
end

def win(code, attempts)
	puts "Congratulations, you cracked the code (#{code}) after #{attempts} attempts!"
	play_again
end

def play_again
	puts "Do you want to play again [y/n]?"
	play_again = $stdin.gets.chomp.downcase
	if play_again == "y"
		master_mind_start
	else	
		puts "Thanks for playing!"
		exit(0)	
	end	
end

master_mind_start