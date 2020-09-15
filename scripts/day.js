const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
const now = new Date();

// today's day of the week
const day = now.getDay();
const dayText = days[day];

// show the day at the top of the document and change title
document.getElementById("title").innerHTML = dayText;
document.getElementsByTagName("title")[0].innerHTML = dayText;

// show only the timetable for today
document.getElementById("d" + day).style.display = "block";
