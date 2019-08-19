// Main function, the entry point for the engine
$(function() {
  var line = function(text) {
    return text + "<br />";
  };

  var input = $("#input");
  var n = 81;
  var m = 40;

  input.append(line(n));
  var firstK40 = m + "";
  var secondK40 = m + "";
  for (var i = 0; i < 40; ++i) {
    firstK40 += " " + i;
    secondK40 += " " + (i + 40);
  }
  for (var i = 0; i < 40; ++i) {
    input.append(line(firstK40));
    input.append(line(secondK40));
  }
  input.append(line("2 0 40"));

  input.append(line(39));
  input.append(line(79));
});
