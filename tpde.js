
const areas = document.querySelectorAll('area');
const imageDisplay = document.getElementById('image-display');
const displayedImage = document.getElementById('displayed-image');

areas.forEach(area => {
    area.addEventListener('click', (e) => {
        e.preventDefault();
        const imgSrc = area.dataset.img;

        // Afficher l'image correspondante
        displayedImage.src = imgSrc;
        imageDisplay.classList.remove('hidden');
    });
});

// Optionnel : Masquer l'image en cliquant dessus
imageDisplay.addEventListener('click', () => {
    imageDisplay.classList.add('hidden');
    displayedImage.src = '';
});

