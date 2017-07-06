# rock_paper_scissors.rb - One of my first scripts in Ruby

# initiating play loop
playing = true
while playing
	puts "Welcome to Rock Paper Scissors!"
	puts "Please choose either ROCK, PAPER or SCISSORS !"
	print "> "

	#getting player choice
	#checking for correct input
	input_check = false
	while input_check == false
		input = gets.chomp.downcase
		if (input == "rock") || (input == "paper") || (input == "scissors")
			puts "> You chose #{input.upcase}"
			input_check = true
		else 
			puts "Invalid input. Please choose either ROCK, PAPER or SCISSORS !"
			print "> "	
		end	
	end

	#getting PC choice
	pc = rand(3)
	case
		when pc == 0
			pc = "rock"
		when pc == 1
			pc = "paper"
		when pc == 2
			pc	= "scissors"
	end
	puts "> PC chose #{pc.upcase}"

	def rps(hum, com)
		if hum == com
			puts "It's a tie!"
			playing = false 	#breaking out of play loop
			playing = true 		#initiating play loop again, game restarts
		elsif hum == "rock"
			if com == "paper"
				puts ">> PC wins!"
			else 
				puts ">> You win!"				
			end
		elsif hum == "paper"
			if com == "scissors"
				puts ">> PC wins!"
			else 
				puts ">> You win!"
			end	
		elsif hum == "scissors"
			if com == "rock"
				puts ">> PC wins!"
			else
				puts ">> You win!"	
			end		
		end	
	end
					
	rps(input, pc)

	puts "Do you want to play again? Y/N"
		play_check = gets.chomp.downcase
		if play_check == "y"
				playing
		else
			playing = false
		end
end							#end of play loop