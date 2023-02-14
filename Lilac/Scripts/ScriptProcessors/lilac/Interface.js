Content.makeFrontInterface(1024, 650);

//Sampler
const var Sampler1 = Synth.getChildSynth("Sampler1");

//Sample Maps
const var sampleMaps = Sampler.getSampleMapList();

//Combo
const var cmbSampleMap = Content.getComponent("cmbSampleMap");
cmbSampleMap.set("items", sampleMaps.join("\n"));  


inline function oncmbSampleMapControl(component, value)
{
Sampler1.asSampler().loadSampleMap(sampleMaps[value-1]);
};

Content.getComponent("cmbSampleMap").setControlCallback(oncmbSampleMapControl);

//Sampler
const var Sampler2 = Synth.getChildSynth("Sampler2");

//Sample Maps
const var sampleMaps2 = Sampler.getSampleMapList();

//Combo
const var cmbSampleMap2 = Content.getComponent("cmbSampleMap2");
cmbSampleMap2.set("items", sampleMaps2.join("\n"));  


inline function oncmbSampleMap2Control(component, value)
{
Sampler2.asSampler().loadSampleMap(sampleMaps[value-1]);
};

Content.getComponent("cmbSampleMap2").setControlCallback(oncmbSampleMap2Control);

//Sampler
const var Sampler3 = Synth.getChildSynth("Sampler3");

//Sample Maps
const var sampleMaps3 = Sampler.getSampleMapList();

//Combo
const var cmbSampleMap3 = Content.getComponent("cmbSampleMap3");
cmbSampleMap3.set("items", sampleMaps3.join("\n"));  


inline function oncmbSampleMap3Control(component, value)
{
Sampler3.asSampler().loadSampleMap(sampleMaps[value-1]);
};

Content.getComponent("cmbSampleMap3").setControlCallback(oncmbSampleMap3Control);

const var ScriptButton1 = Content.getComponent("ScriptButton1");

const var ScriptPanel1 = Content.getComponent("ScriptPanel1");

inline function onScriptButton1Control(component, value)
{

      ScriptPanel1.showControl(value);
      ScriptPanel1.showControl(1-value); 
};

Content.getComponent("ScriptButton1").setControlCallback(onScriptButton1Control);



function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 