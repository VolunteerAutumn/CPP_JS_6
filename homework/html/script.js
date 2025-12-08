const ul = document.querySelector('ul');

function addCard(imgSrc, name) {
    const newLi = document.createElement('li');
    newLi.className = 'card';

    const img = document.createElement('img');
    img.src = imgSrc;
    img.alt = name;

    const h3 = document.createElement('h3');
    h3.textContent = name;

    newLi.appendChild(img);
    newLi.appendChild(h3);

    ul.appendChild(newLi);
}

document.getElementById('addFish').addEventListener('click', () => {
    addCard('img/fish.png', 'Fish');
});

document.getElementById('addApple').addEventListener('click', () => {
    addCard('img/apple.png', 'Apple');
});

document.getElementById('addEggs').addEventListener('click', () => {
    addCard('img/eggs.png', 'Eggs');
});
