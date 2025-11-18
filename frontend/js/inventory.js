const print = msg => console.log(msg);

// Show messages on the page
const output = document.createElement("div");
output.id = "output";
output.style.marginTop = "20px";
output.style.color = "lightgreen";
document.body.appendChild(output);

function show(msg) {
  output.textContent = msg;
}

// Insert
document.getElementById("insertBtn").onclick = () => {
  const id = document.getElementById("itemId").value;
  const name = document.getElementById("itemName").value;
  const qty = document.getElementById("itemQty").value;
  const price = document.getElementById("itemPrice").value;

  show(`Insert: ${name} (ID: ${id})`);
};

// Search
document.getElementById("searchBtn").onclick = () => {
  const id = document.getElementById("searchId").value;
  show(`Search for item ID: ${id}`);
};

// Update
document.getElementById("updateBtn").onclick = () => {
  const id = document.getElementById("updateId").value;
  const qty = document.getElementById("updateQty").value;

  show(`Update item ${id} → new quantity: ${qty}`);
};

// Display
document.getElementById("displayBtn").onclick = () => {
  show("Display all items (placeholder)");
};
