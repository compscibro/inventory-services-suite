const print = msg => console.log(msg);

document.getElementById("insertBtn").onclick = () => print("Insert requested");
document.getElementById("searchBtn").onclick = () => print("Search requested");
document.getElementById("updateBtn").onclick = () => print("Update requested");
document.getElementById("displayBtn").onclick = () => print("Display requested");
