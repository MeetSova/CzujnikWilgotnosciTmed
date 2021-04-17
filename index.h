const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.4/Chart.js "></script>
        <style>
            table{
                margin: auto;
            }
            table, tr, td{
                border: 1px solid black;
                border-collapse: collapse;
            }
            td{
                padding: 5px;
            }
            .wykres{
                width: 90%;
            }
            .container{
                margin: auto;
                width: 50%;
                background-color: lightgrey;
            }
        </style>
    </head>
    <body>
        <div class="container">
        <div class="wykres">
            <canvas id="myChart" width="400" height="400"></canvas>
            </div>
        <p>Aktualna wilgotność: <span id="actualvalue"></span></p>
        <input style="display: block; margin: auto; margin-bottom: 5px;" type="button" onclick="showdata()" value="Zobacz historię pomiaru">
        <div id="dane" style="margin=: 5px;"></div>
        
        </div>
        
        
        
        
        
<script>
var ctx = document.getElementById('myChart').getContext('2d');
var myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: [],
        datasets: [{
            label: 'Wilgotność',
            data: [],
            borderWidth: 1
        }]
    },
    options: {
        scales: {
            yAxes: [{
                ticks: {
                    beginAtZero: true,
                    suggestedMax: 100,
                },
                display: true,
                scaleLabel: {
                    display: true,
                    labelString: 'Zmierzona wilgotność w %'
                }
            }],
            xAxes: [{
                display: true,
                scaleLabel: {
                    display: true,
                    labelString: 'Godzina pomiaru'
                }
            }],
            animation: {
                duration: 0 // general animation time
             },
            hover: {
                animationDuration: 0 // duration of animations when hovering an item
            },
                responsiveAnimationDuration: 0 // animation duration after a resize
        }
    }
});
    
function addData(chart, label, data) {
    chart.data.labels.push(label);
    chart.data.datasets.forEach((dataset) => {
        dataset.data.push(data);
    });
    chart.update();
}

function removeData(chart) {
    chart.data.labels.pop();
    chart.data.datasets.forEach((dataset) => {
        dataset.data.pop();
    });
    chart.update();
}
</script>
        
               <script>

var odbierz = "NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan NULL nan ";

            var time = ["NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"];
            var hum = ["nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan", "nan"];
            var i;
            var j;

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
  gettable();
}, 2000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('actualvalue').innerHTML = this.responseText;
      
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}

function gettable() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      odbierz = this.responseText;
      console.log(odbierz);
        var tab = odbierz.split(" ");
        j = 0;
            for(i = 0; i<288; i=i+2){
                time[j]=tab[i];
                if(tab[i+1] == "nan"){
                    hum[j]=0.01;
                }
                else{
                    hum[j]=tab[i+1];
                }
                j++;
            }
            var arraye = hum.map(Number);
        console.log(time);
        console.log(hum);
        
        for(z = 0; z < 144; z++){
        removeData(myChart);
        }
        for(z = 0; z < 144; z++){
        if(time[z] != "NULL" && hum[z] != 0.01){
            addData(myChart, time[z], arraye[z]);                   
        }
        }
    }
  };
  xhttp.open("GET", "readTAB", true);
  xhttp.send();
}

console.log(odbierz);


            
function showdata(){
    var z;
    var str = "<table><tr><td>ID</td><td>Godzina Pomiaru</td><td>Wilgotność [%]</td></tr>";
    for(z = 0; z < 144; z++){
        if(time[z] != "NULL" && hum[z] != 0.01){
            str+="<tr><td>"+z+"</td><td>"+time[z]+ "</td><td>"+hum[z]+"% </td></tr>";
            addData(myChart, time[z], hum[z]);                   
        }
    }
    str+="</table>";
    document.getElementById('dane').innerHTML = str;
}

    

</script>
 
    </body>

    
</html>
)=====";
