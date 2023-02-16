#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace FX_impl
{
// =========================| Node & Parameter type declarations |=========================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

using xfader_c0 = parameter::from0To1<core::gain, 
                                      0, 
                                      xfader_c0Range>;

using xfader_c1 = xfader_c0;

using xfader_multimod = parameter::list<xfader_c0, xfader_c1>;

using xfader_t = control::xfader<xfader_multimod, faders::linear>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::granul<NV>>, 
                                  core::gain>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t>, 
                                 chain1_t<NV>>;

using multi_t = container::multi<parameter::empty, 
                                 wrap::fix<2, core::empty>>;

template <int NV>
using wrapfaust11_t = container::chain<parameter::empty, 
                                       wrap::fix<2, xfader_t>, 
                                       split_t<NV>, 
                                       multi_t>;

namespace FX_t_parameters
{
// Parameter list for FX_impl::FX_t -------------------------------------------------------

using mix = parameter::plain<FX_impl::xfader_t, 0>;
template <int NV>
using delaytime = parameter::plain<project::granul<NV>, 0>;
template <int NV>
using damp = parameter::plain<project::granul<NV>, 1>;
template <int NV>
using size = parameter::plain<project::granul<NV>, 2>;
template <int NV>
using diffusion = parameter::plain<project::granul<NV>, 3>;
template <int NV>
using feedback = parameter::plain<project::granul<NV>, 4>;
template <int NV>
using moddepth = parameter::plain<project::granul<NV>, 5>;
template <int NV>
using modfreq = parameter::plain<project::granul<NV>, 6>;
template <int NV>
using FX_t_plist = parameter::list<mix, 
                                   delaytime<NV>, 
                                   damp<NV>, 
                                   size<NV>, 
                                   diffusion<NV>, 
                                   feedback<NV>, 
                                   moddepth<NV>, 
                                   modfreq<NV>>;
}

template <int NV>
using FX_t_ = container::chain<FX_t_parameters::FX_t_plist<NV>, 
                               wrap::fix<2, wrapfaust11_t<NV>>>;

// =============================| Root node initialiser class |=============================

template <int NV> struct instance: public FX_impl::FX_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(FX);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(132)
		{
			0x005B, 0x0000, 0x6D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x543F, 0x06C5, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x6564, 0x616C, 0x7479, 0x6D69, 0x0065, 0x126E, 0x3A83, 
            0x9999, 0x3FB9, 0xCFAB, 0x3EB5, 0x0000, 0x3F80, 0xB717, 0x38D1, 
            0x025B, 0x0000, 0x6400, 0x6D61, 0x0070, 0x0000, 0x0000, 0x70A4, 
            0x3F7D, 0x49BB, 0x3F0C, 0x0000, 0x3F80, 0x126F, 0x3A83, 0x035B, 
            0x0000, 0x7300, 0x7A69, 0x0065, 0x0000, 0x3F00, 0x0000, 0x4040, 
            0x923A, 0x3FF3, 0x0000, 0x3F80, 0xB717, 0x38D1, 0x045B, 0x0000, 
            0x6400, 0x6669, 0x7566, 0x6973, 0x6E6F, 0x0000, 0x0000, 0xA400, 
            0x7D70, 0x143F, 0x463F, 0x003F, 0x8000, 0x173F, 0xD1B7, 0x5B38, 
            0x0005, 0x0000, 0x6566, 0x6465, 0x6162, 0x6B63, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x3D3F, 0x170A, 0x003F, 0x8000, 0x0A3F, 0x23D7, 
            0x5B3C, 0x0006, 0x0000, 0x6F6D, 0x6464, 0x7065, 0x6874, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x6F3F, 
            0x8312, 0x5B3A, 0x0007, 0x0000, 0x6F6D, 0x6664, 0x6572, 0x0071, 
            0x0000, 0x0000, 0x0000, 0x4120, 0x851E, 0x3EEB, 0x0000, 0x3F80, 
            0xD70A, 0x3C23, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ----------------------------------------------------------------
		
		auto& wrapfaust11 = this->getT(0);                    // FX_impl::wrapfaust11_t<NV>
		auto& xfader = this->getT(0).getT(0);                 // FX_impl::xfader_t
		auto& split = this->getT(0).getT(1);                  // FX_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(0);          // FX_impl::chain_t
		auto& gain = this->getT(0).getT(1).getT(0).getT(0);   // core::gain
		auto& chain1 = this->getT(0).getT(1).getT(1);         // FX_impl::chain1_t<NV>
		auto& faust1 = this->getT(0).getT(1).getT(1).getT(0); // project::granul<NV>
		auto& gain1 = this->getT(0).getT(1).getT(1).getT(1);  // core::gain
		auto& multi = this->getT(0).getT(2);                  // FX_impl::multi_t
		
		// Parameter Connections ----------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // mix -> xfader::Value
		
		this->getParameterT(1).connectT(0, faust1); // delaytime -> faust1::delayTime
		
		this->getParameterT(2).connectT(0, faust1); // damp -> faust1::damping
		
		this->getParameterT(3).connectT(0, faust1); // size -> faust1::size
		
		this->getParameterT(4).connectT(0, faust1); // diffusion -> faust1::diffusion
		
		this->getParameterT(5).connectT(0, faust1); // feedback -> faust1::feedback
		
		this->getParameterT(6).connectT(0, faust1); // moddepth -> faust1::modDepth
		
		this->getParameterT(7).connectT(0, faust1); // modfreq -> faust1::modFreq
		
		// Modulation Connections ---------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1); // xfader -> gain1::Gain
		
		// Default Values -----------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // faust1::delayTime is automated
		; // faust1::damping is automated
		; // faust1::size is automated
		; // faust1::diffusion is automated
		; // faust1::feedback is automated
		; // faust1::modDepth is automated
		; // faust1::modFreq is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.526448);
		this->setParameterT(1, 0.3551);
		this->setParameterT(2, 0.548);
		this->setParameterT(3, 1.9029);
		this->setParameterT(4, 0.7744);
		this->setParameterT(5, 0.59);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.46);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ==================================| Public Definition |==================================

namespace project
{
// polyphonic template declaration

template <int NV>
using FX = wrap::node<FX_impl::instance<NV>>;
}


