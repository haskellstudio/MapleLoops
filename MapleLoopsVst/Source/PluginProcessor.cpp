/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "CefContextJob.h"
#include "CefContext.h"

int MapleLoopsAudioProcessor::instanceCount=0;
ThreadPool * MapleLoopsAudioProcessor::cefThreadContextPool=nullptr;
CefContextJob *  MapleLoopsAudioProcessor::context_thread = nullptr;
//==============================================================================
MapleLoopsAudioProcessor::MapleLoopsAudioProcessor()
{


	if (cefThreadContextPool == nullptr){
		cefThreadContextPool = new ThreadPool(1);
	}
	
	instanceCount++;


}

MapleLoopsAudioProcessor::~MapleLoopsAudioProcessor()
{

	instanceCount--;

	//here we reset the track ID counter if the last plugin is deleted
	//then the system is totally reset even though the java and supporting
	//infrastructure treamins attached to the process
	if (instanceCount == 0)
	{
		if (cefThreadContextPool != nullptr)
		{
			if (cefThreadContextPool->getNumJobs() == 0){
				cefThreadContextPool->removeAllJobs(true, 1000);
				delete cefThreadContextPool;
			}
		}

	}
}

//==============================================================================
const String MapleLoopsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MapleLoopsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MapleLoopsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MapleLoopsAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double MapleLoopsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MapleLoopsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MapleLoopsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MapleLoopsAudioProcessor::setCurrentProgram (int index)
{
}

const String MapleLoopsAudioProcessor::getProgramName (int index)
{
    return String();
}

void MapleLoopsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MapleLoopsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MapleLoopsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void MapleLoopsAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool MapleLoopsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MapleLoopsAudioProcessor::createEditor()
{
    return new MapleLoopsAudioProcessorEditor (*this);
}

//==============================================================================
void MapleLoopsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MapleLoopsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MapleLoopsAudioProcessor();
}
