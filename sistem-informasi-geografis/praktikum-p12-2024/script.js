const sidebar = document.getElementById("sidebar");
const toggleBtn = document.getElementById("toggle-btn");

toggleBtn.addEventListener("click", () => {
  sidebar.classList.toggle("collapsed");
  document.querySelector("main").classList.toggle("collapsed");
});

// Toggle Statistik
document.getElementById('toggle-statistics').addEventListener('click', () => {
    const statisticsSection = document.getElementById('statistics-section');
    const mapsSection = document.querySelector('.webgis-content');

    statisticsSection.classList.toggle('collapsed');

    if (statisticsSection.classList.contains('collapsed')) {
        mapsSection.style.flex = '1';
    } else {
        mapsSection.style.flex = '0.25';
    }
});
