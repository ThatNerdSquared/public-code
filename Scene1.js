const fs = require("fs")
const {createCanvas, loadImage} = require("canvas")
const canvas = createCanvas(2000, 2000)
const ctx = canvas.getContext("2d")

function newCircle(x, y, radius, fillColour) {
	ctx.beginPath()
	ctx.arc(x, y, radius, 0, 2 * Math.PI);
	ctx.lineWidth = 14
	ctx.closePath()
	ctx.fillStyle = fillColour
	ctx.fill()
	ctx.stroke()
}
function newEllipse(x, y, xRadius, yRadius, fillColour) {
	ctx.beginPath()
	ctx.ellipse(x, y, xRadius, yRadius, 0, 0, 2 * Math.PI);
	ctx.lineWidth = 14
	ctx.closePath()
	ctx.fillStyle = fillColour
	ctx.fill()
	ctx.stroke()
}

function drawSnowman(smileNum) {
	ctx.strokeStyle = "black"
	// Drawing the body.
	// newCircle(1000, 1500, 200, "white") // bottom circle
	newEllipse(1000, 1500, 200, 185, "white")
	// newCircle(1000, 1250, 175, "white") // middle circle
	newEllipse(1000, 1250, 170, 160, "white")
	// newCircle(1000, 1000, 150, "white") // top circle
	newEllipse(1000, 1000, 150, 145, "white")
	
	// Drawing the eyes.
	newCircle(940, 990, 15, "black")
	newCircle(1060, 990, 15, "black")
	
	// Drawing the buttons.
	newCircle(1000, 1210, 20, "black")
	newCircle(1000, 1290, 20, "black")
	
	// Drawing the smile.
	newCircle(940, smileNum, 5, "black")
	newCircle(980, 1080, 5, "black")
	newCircle(1020, 1080, 5, "black")
	newCircle(1060, smileNum, 5, "black")
	
	// Drawing the nose.
	ctx.beginPath()
	ctx.lineWidth = 8
	ctx.moveTo(1000, 1000)
	ctx.lineTo(1120, 1040)
	ctx.lineTo(1000, 1040)
	ctx.fillStyle = "#FA9500"
	ctx.fill()
	ctx.stroke()
	
	// Drawing the arms.
	// Drawing right arm.
	ctx.beginPath()
	ctx.lineWidth = 14
	ctx.moveTo(1170, 1250)
	ctx.lineTo(1340, 1090)
	ctx.closePath()
	ctx.stroke()
	// hand line 1
	ctx.beginPath()
	ctx.moveTo(1281.563, 1150)
	ctx.lineTo(1281.563, 1080)
	ctx.closePath()
	ctx.stroke()
	// hand line 2
	ctx.beginPath()
	ctx.moveTo(1281.563, 1150)
	ctx.lineTo(1340, 1150)
	ctx.closePath()
	ctx.stroke()
	
	// Drawing left arm.
	ctx.beginPath()
	ctx.lineWidth = 14
	ctx.moveTo(830, 1250)
	ctx.lineTo(660, 1090)
	ctx.closePath()
	ctx.stroke()
	// hand line 1
	ctx.beginPath()
	ctx.moveTo(718.437, 1150)
	ctx.lineTo(718.437, 1080)
	ctx.closePath()
	ctx.stroke()
	// hand line 2
	ctx.beginPath()
	ctx.moveTo(718.437, 1150)
	ctx.lineTo(660, 1150)
	ctx.closePath()
	ctx.stroke()
	
	// Drawing the top hat.
	// basic structure
	newEllipse(1000, 880, 150, 50, "black")
	ctx.fillRect(915, 650, 170, 200)
	ctx.stroke()
	// hat strip
	ctx.beginPath()
	ctx.strokeStyle = "yellow"
	ctx.moveTo(1080, 810)
	ctx.lineTo(1080, 850)
	ctx.stroke()
	ctx.beginPath()
	let degrees = 45
	let radians = (Math.PI/180)*degrees
	let degrees2 = 133
	let radians2 = (Math.PI/180)*degrees2
	ctx.arc(1000, 750, 125, radians, radians2)
	ctx.lineTo(915, 810)
	ctx.stroke()
	ctx.beginPath()
	degrees = 35
	radians = (Math.PI/180)*degrees
	degrees2 = 145
	radians2 = (Math.PI/180)*degrees2
	ctx.arc(1000, 750, 100, radians, radians2)
	ctx.stroke()
	
	// TODO: animate this scene!
	
	// TODO: turn the snowman into a func?
	
}
let i = -600

for(i = -600; i < 100; i=i+10) {
	ctx.setTransform(1, 0, 0, 1, 0, 0);
	console.log(i)
	// ctx.clearRect(0, 0, canvas.width, canvas.height)
	ctx.fillStyle = "white"
	ctx.fillRect(0, 0, canvas.width, canvas.height)
	ctx.translate(0, i)
	drawSnowman(1060)
	const buffer = canvas.toBuffer("image/png")
	fs.writeFileSync("./image" + i.toString() + ".png", buffer)
	console.log("done")
}
let t = 100
for(i = 1060; i <= 1100; i=i+1) {
	ctx.fillStyle = "white"
	ctx.fillRect(0, 0, canvas.width, canvas.height)
	drawSnowman(i)
	const buffer = canvas.toBuffer("image/png")
	fs.writeFileSync("./image" + t.toString() + ".png", buffer)
	console.log("done")
	t=t+50
}


// i = i+100
// if (100 <= i) {
// 	clearInterval(animInit)
// }
// let animInit = setInterval(animation(), 3000);

// ctx.translate(0, -600)
// drawSnowman()

// const buffer = canvas.toBuffer("image/png")
// fs.writeFileSync("./image.png", buffer)
// console.log("done")