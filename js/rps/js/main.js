// Variables for rectangles
var margin = 50;
var rectWidth = 70;
var rectHeight = 70;

// Variables for color and user board
var playerWins = 0;
var playerColor = "#40ff3b";

var pcWins = 0;
var pcColor = "#ff3c41";

// Stores the choice (rock, paper or scissors)
var choice = {
    player: "",
    pc: ""
};

// Game state
var choosing = true;
var resolving = false;

// Color for middle text
var defColor = "#000";

var round = 1;

/*
var sprites = {};

sprites.rock = new Image();
sprites.rock.src = 'img/rock.png';

sprites.paper = new Image();
sprites.paper.src = 'img/paper.png';

sprites.scissors = new Image();
sprites.scissors.src = 'img/scissors.png';

sprites.background = new Image();
sprites.background.src = 'img/background.png';
*/

// Bottom rectangles
var rRock = {
    x: 45,
    y: 300,
    w: rectWidth,
    h: rectHeight
};

var rPaper = {
    x: rRock.x + rRock.w + margin,
    y: rRock.y,
    w: rectWidth,
    h: rectHeight
};

var rScissors = {
    x: rPaper.x + rPaper.w + margin,
    y: rPaper.y,
    w: rectWidth,
    h: rectHeight
};

var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");

// Creating our board
initBoard();

canvas.addEventListener('click', handleClick);
function handleClick(e) {
    console.log('click: ' + e.offsetX + '/' + e.offsetY);

    // Game state: Player chooses rectangle
    if (choosing) {
        // Rock
        if (e.offsetX >= rRock.x && e.offsetX <= (rRock.x + rRock.w)
            && e.offsetY >= rRock.y && e.offsetY <= (rRock.y + rRock.h)) {
            console.log('Clicked Rock');
            // choseRock();
            choice.player = "Rock";
            choice.pc = turnPc();

            resolve(choice);
        }

        // Scissors
        if (e.offsetX >= rScissors.x && e.offsetX <= (rScissors.x + rScissors.w)
            && e.offsetY >= rScissors.y && e.offsetY <= (rScissors.y + rScissors.h)) {
            console.log('Clicked Scissors');
            // choseScissors();
            choice.player = "Scissors";
            choice.pc = turnPc();

            resolve(choice);
        }

        // Paper
        if (e.offsetX >= rPaper.x && e.offsetX <= (rPaper.x + rPaper.w)
            && e.offsetY >= rPaper.y && e.offsetY <= (rPaper.y + rPaper.h)) {
            console.log('Clicked Paper');
            // chosePaper();
            choice.player = "Paper";
            choice.pc = turnPc();

            resolve(choice);
        }
    }

    // Game state: turn is resolved
    else if (resolving) {
        chooseRPS();
    }
}

// Checking win/lose condition
function chooseRPS() {
    if (playerWins == 3) {
        initBoard();
        clearRects();

		ctx.font = "18px Arial";
		ctx.fillStyle = defColor;
		ctx.fillText("Congratulations, you've won the game!", 50,200);

        setTimeout(function() {
            window.location = "";
        }, 5000);
    }

    else if (pcWins == 3) {
		initBoard();
		clearRects();

		ctx.font = "18px Arial";
		ctx.fillStyle = defColor;
		ctx.fillText("Too bad, PC has won the game!", 70,200);

		setTimeout(function() {
			window.location = "";
		}, 5000);
    }

    else {
        choosing = true;
        initBoard();
    }
}

// Initializing board
function initBoard() {
    ctx.clearRect(0, 0, 400, 400);

    // Drawing scores
    ctx.font = "20px Arial";
    ctx.fillStyle = playerColor;
    ctx.fillText("Player: " + playerWins,15,30);

    ctx.fillStyle = pcColor;
    ctx.fillText("PC: " + pcWins,330,30);

    // Drawing rectangles
    drawRect(rRock.x, rRock.y, rRock.w, rRock.h, playerColor, "Rock");
    drawRect(rPaper.x, rPaper.y, rPaper.w, rPaper.h, playerColor, "Paper");
    drawRect(rScissors.x, rScissors.y, rScissors.w, rScissors.h, playerColor, "Scissors");

	/*
	 ctx.drawImage(sprites.background, 0, 0);
	 ctx.drawImage(sprites.rock, rRock.x, rRock.y);
	 ctx.drawImage(sprites.paper, rPaper.x, rPaper.y);
	 ctx.drawImage(sprites.scissors, rScissors.x, rScissors.y);
	 */
}

// Main game logic
function resolve(choice) {
    choosing = false;
    resolving = true;

	// Position of new player rectangle
    var newPlayerX = 70;
    var newPlayerY = 140;

	// Position of vs-text
    var vsX = newPlayerX + 130;

	// Position of new PC rectangle
    var newPcX = newPlayerX + 200;
    var newPcY = newPlayerY;

    // ROCK vs PAPER
    if (choice.player == "Rock" && choice.pc == "Paper") {
        console.log('Player == '+ choice.player + '&& PC == ' + choice.pc);
        clearRects();

        drawRect(newPlayerX, newPlayerY, rectWidth, rectHeight, playerColor, choice.player);
        ctx.fillText("vs.", vsX, newPlayerY + 40);
        drawRect(newPcX, newPcY, rectWidth, rectHeight, pcColor, choice.pc);

        textMid("PC Wins!");
        pcWins++;
    }
    // ROCK vs SCISSORS
    else if (choice.player == "Rock" && choice.pc == "Scissors") {
        console.log('Player == ' + choice.player + '&& PC == ' + choice.pc);
        clearRects();

        drawRect(newPlayerX, newPlayerY, rectWidth, rectHeight, playerColor, choice.player);
        ctx.fillText("vs.", vsX, newPlayerY + 40);
        drawRect(newPcX, newPcY, rectWidth, rectHeight, pcColor, choice.pc);

        textMid("You win!");
        playerWins++;
    }
    // PAPER vs SCISSORS
    else if (choice.player == "Paper" && choice.pc == "Scissors") {
        console.log('Player == ' + choice.player + '&& PC == ' + choice.pc);
        clearRects();

        drawRect(newPlayerX, newPlayerY, rectWidth, rectHeight, playerColor, choice.player);
        ctx.fillText("vs.", vsX, newPlayerY + 40);
        drawRect(newPcX, newPcY, rectWidth, rectHeight, pcColor, choice.pc);

		textMid("PC Wins!");
		pcWins++;
    }
    // PAPER vs ROCK
	else if (choice.player == "Paper" && choice.pc == "Rock") {
		console.log('Player == ' + choice.player + '&& PC == ' + choice.pc);
		clearRects();

		drawRect(newPlayerX, newPlayerY, rectWidth, rectHeight, playerColor, choice.player);
		ctx.fillText("vs.", vsX, newPlayerY + 40);
		drawRect(newPcX, newPcY, rectWidth, rectHeight, pcColor, choice.pc);

		textMid("You win!");
		playerWins++;
	}
    // SCISSORS vs PAPER
	else if (choice.player == "Scissors" && choice.pc == "Paper") {
		console.log('Player == ' + choice.player + '&& PC == ' + choice.pc);
		clearRects();

		drawRect(newPlayerX, newPlayerY, rectWidth, rectHeight, playerColor, choice.player);
		ctx.fillText("vs.", vsX, newPlayerY + 40);
		drawRect(newPcX, newPcY, rectWidth, rectHeight, pcColor, choice.pc);

		textMid("You win!");
		playerWins++;
	}
    // SCISSORS vs ROCK
	else if (choice.player == "Scissors" && choice.pc == "Rock") {
		console.log('Player == ' + choice.player + '&& PC == ' + choice.pc);
		clearRects();

		drawRect(newPlayerX, newPlayerY, rectWidth, rectHeight, playerColor, choice.player);
		ctx.fillText("vs.", vsX, newPlayerY + 40);
		drawRect(newPcX, newPcY, rectWidth, rectHeight, pcColor, choice.pc);

		textMid("PC wins!");
		pcWins++;
	}
	// DRAW
	else {
		console.log('Player == ' + choice.player + '&& PC == ' + choice.pc);
		clearRects();

		drawRect(newPlayerX, newPlayerY, rectWidth, rectHeight, playerColor, choice.player);
		ctx.fillText("vs.", vsX, newPlayerY + 40);
		drawRect(newPcX, newPcY, rectWidth, rectHeight, pcColor, choice.pc);

		textMid("Draw!");
    }
}

// Handles PC choice
function turnPc() {
    var temp = Math.floor(Math.random() * 3);
    switch (temp) {
        case 0:
            console.log('PC chose rock');
            return "Rock";
            break;
        case 1:
            console.log('PC chose paper');
            return "Paper";
            break;
        case 2:
            console.log('PC chose scissors');
            return "Scissors";
            break;
    }
}

// Display middle text
function textMid(inputString) {
	ctx.font = "20px Arial";
	ctx.fillStyle = defColor;
	ctx.fillText(inputString, 180,100);
}

// Drawing rectangles
function drawRect(x, y, w, h, color, text) {
    ctx.fillStyle = color;
    ctx.fillRect(x, y, w, h);
    ctx.font = "16px Arial";
    ctx.fillStyle = "#000";
    ctx.fillText(text, x + 5, y + 40);
}

// Clearing rectangles
function clearRects() {
    clearRock();
    clearPaper();
    clearScissors();
}

function clearRock() {
    ctx.clearRect(rRock.x, rRock.y, rRock.w, rRock.h);
}

function clearPaper() {
    ctx.clearRect(rPaper.x, rPaper.y, rPaper.w, rPaper.h);
}

function clearScissors() {
    ctx.clearRect(rScissors.x, rScissors.y, rScissors.w, rScissors.h);
}
