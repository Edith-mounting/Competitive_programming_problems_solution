
class DelayInformation
{
	Double timeDelay;
    public:
    void set_timeDelay(Double timeDelay){
        timeDelay = timeDelay;
    }
    double get_timeDelay(){
        return timeDelay;
    }
}

class FlightDetails
{
	Flight flight;
	List<DelayInformation> delayInfos;
    public:
    //set the delay_information
    void set_delayInfo(List<DelayInformation> delayInfos){
        for every_time_delay_ in delayInfos:
            set_timeDelay(every_time_delay);
    }
}

Double getDelayForFlight(FlightDetails flightDetail)
{
	//calculating the total info by summing each delayInfos in this flightDetails
    double total_delay = 0;
    for every_time in FlightDetails.delayInfos:
    // we are iterating over all times in DelayInformation and adding it to total_delay
        total_delay += every_time;

    return total_delay;
}

void showDashBoard(List<FlightDetails> flightDetails)
{
	//calculate getDelayForFlight for each flightDetail and show 

}
// alert functions
publish('event', 'This is my payload', function(err) {
  if(err) {
    System.out.println('Unable to publish message; err = ' + err.message);
  } else {
    System.out.println('Message successfully sent');
  }
});
subscribe(function(message) {
  System.out.println('message received for event ' + message.name);
  System.out.println('message data:' + message.data);
});