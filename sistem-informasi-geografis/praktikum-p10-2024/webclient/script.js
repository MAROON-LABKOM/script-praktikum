var map = L.map("map").setView([0, 0], 15);
L.tileLayer("https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png", {
  attribution: "© OpenStreetMap contributors",
}).addTo(map);

// Function to fetch data from the API
function fetchData() {
  // Replace 'YOUR_API_ENDPOINT' with the actual API endpoint
  var apiUrl =
    "YOUR READ API";

  // Fetch data from the API
  fetch(apiUrl)
    .then((response) => response.json())
    .then((data) => {
      // Update the map with the new data
      console.log("Response JSON:", data);
      updateMarker(data);

      // Update field3 and field4 in the HTML
      document.getElementById("field3").innerText = parseFloat(
        data.field3
      ).toFixed(2);
      document.getElementById("field4").innerText = parseFloat(
        data.field4
      ).toFixed(2);
      document.getElementById("coodinate").innerText =
        data.field1 + " " + data.field2;

      fetch(
        `https://nominatim.openstreetmap.org/reverse?lat=${data.field1}&lon=${data.field2}&format=json`
      )
        .then((response2) => response2.json())
        .then((dataLoc) => {
          document.getElementById("type").innerText = dataLoc.type;
          document.getElementById("place").innerText = dataLoc.display_name;
        });
    })
    .catch((error) => console.error("Error fetching data:", error));
}

// Function to update markers on the map
function updateMarker(location) {
  var latLng = [parseFloat(location.field1), parseFloat(location.field2)];
  // Remove existing marker
  map.eachLayer(function (layer) {
    if (layer instanceof L.Marker) {
      map.removeLayer(layer);
    }
  });

  // Add new marker based on the API response
  var marker = L.marker([
    parseFloat(location.field1),
    parseFloat(location.field2),
  ]).addTo(map);
  map.setView(latLng, map.getZoom());
}

// Initial fetch when the page loads
fetchData();

// Fetch data every 10 seconds (adjust the interval as needed)
setInterval(fetchData, 10000);
