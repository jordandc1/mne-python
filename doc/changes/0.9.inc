.. _changes_0_9:

Version 0.9 (2015-05-22)
------------------------

Changelog
~~~~~~~~~

- Add support for mayavi figures in ``add_section`` method in Report by `Mainak Jas`_

- Add extract volumes of interest from freesurfer segmentation and setup as volume source space by `Alan Leggitt`_

- Add support to combine source spaces of different types by `Alan Leggitt`_

- Add support for source estimate for mixed source spaces by `Alan Leggitt`_

- Add ``SourceSpaces.save_as_volume`` method by `Alan Leggitt`_

- Automatically compute proper box sizes when generating layouts on the fly by `Marijn van Vliet`_

- Average evoked topographies across time points by `Denis Engemann`_

- Add option to Report class to save images as vector graphics (SVG) by `Denis Engemann`_

- Add events count to ``mne.viz.plot_events`` by `Denis Engemann`_

- Add support for stereotactic EEG (sEEG) channel type by `Marmaduke Woodman`_

- Add support for montage files by `Denis Engemann`_, `Marijn van Vliet`_, `Jona Sassenhagen`_, `Alex Gramfort`_ and `Teon Brooks`_

- Add support for spatiotemporal permutation clustering on sensors by `Denis Engemann`_

- Add support for multitaper time-frequency analysis by `Hari Bharadwaj`_

- Add Stockwell (S) transform for time-frequency representations by `Denis Engemann`_ and `Alex Gramfort`_

- Add reading and writing support for time frequency data (AverageTFR objects) by  `Denis Engemann`_

- Add reading and writing support for digitizer data, and function for adding dig points to info by `Teon Brooks`_

- Add  ``plot_projs_topomap`` method to ``Raw``, ``Epochs`` and ``Evoked`` objects by `Teon Brooks`_

- Add EEG (based on spherical splines) and MEG (based on field interpolation) bad channel interpolation method to ``Raw``, ``Epochs`` and ``Evoked`` objects by `Denis Engemann`_ and `Mainak Jas`_

- Add parameter to ``whiten_evoked``, ``compute_whitener`` and ``prepare_noise_cov`` to set the exact rank by `Martin Luessi`_ and `Denis Engemann`_

- Add fiff I/O for processing history and MaxFilter info by `Denis Engemann`_ and `Eric Larson`_

- Add automated regularization with support for multiple sensor types to ``compute_covariance`` by `Denis Engemann`_ and `Alex Gramfort`_

- Add ``Evoked.plot_white`` method to diagnose the quality of the estimated noise covariance and its impact on spatial whitening by `Denis Engemann`_ and `Alex Gramfort`_

- Add ``mne.evoked.grand_average`` function to compute grand average of Evoked data while interpolating bad EEG channels if necessary by `Mads Jensen`_ and `Alex Gramfort`_

- Improve EEG referencing support and add support for bipolar referencing by `Marijn van Vliet`_ and `Alex Gramfort`_

- Enable TFR calculation on Evoked objects by `Eric Larson`_

- Add support for combining Evoked datasets with arbitrary weights (e.g., for oddball paradigms) by `Eric Larson`_ and `Alex Gramfort`_

- Add support for concatenating a list of Epochs objects by `Denis Engemann`_

- Labels support subtraction (``label_1 - label_2``) by `Christian Brodbeck`_

- Add GeneralizationAcrossTime object with support for cross-condition generalization by `Jean-Remi King`_ and `Denis Engemann`_

- Add support for single dipole fitting by `Eric Larson`_

- Add support for spherical models in forward calculations by `Eric Larson`_

- Add support for SNR estimation by `Eric Larson`_

- Add support for Savitsky-Golay filtering of Evoked and Epochs by `Eric Larson`_

- Add support for adding an empty reference channel to data by `Teon Brooks`_

- Add reader function ``mne.io.read_raw_fif`` for Raw FIF files by `Teon Brooks`_

- Add example of creating MNE objects from arbitrary data and NEO files by `Jaakko Leppakangas`_

- Add ``plot_psd`` and ``plot_psd_topomap`` methods to epochs by `Yousra Bekhti`_, `Eric Larson`_ and `Denis Engemann`_

- ``evoked.pick_types``, ``epochs.pick_types``, and ``tfr.pick_types`` added by `Eric Larson`_

- ``rename_channels`` and ``set_channel_types`` added as methods to ``Raw``, ``Epochs`` and ``Evoked`` objects by `Teon Brooks`_

- Add RAP-MUSIC inverse method by `Yousra Bekhti`_ and `Alex Gramfort`_

- Add ``evoked.as_type`` to  allow remapping data in MEG channels to virtual magnetometer or gradiometer channels by `Mainak Jas`_

- Add :meth:`mne.Report.add_bem_to_section`, :meth:`mne.Report.add_htmls_to_section` methods to :class:`mne.Report` by `Teon Brooks`_

- Add support for KIT epochs files with ``read_epochs_kit`` by `Teon Brooks`_

- Add whitening plots for evokeds to ``mne.Report`` by `Mainak Jas`_

- Add ``DigMontage`` class and reader to interface with digitization info by `Teon Brooks`_ and `Christian Brodbeck`_

- Add ``set_montage`` method to the ``Raw``, ``Epochs``, and ``Evoked`` objects by `Teon Brooks`_ and `Denis Engemann`_

- Add support for capturing sensor positions when clicking on an image by `Chris Holdgraf`_

- Add support for custom sensor positions when creating Layout objects by `Chris Holdgraf`_

BUG
~~~

- Fix energy conservation for STFT with tight frames by `Daniel Strohmeier`_

- Fix incorrect data matrix when tfr was plotted with parameters ``tmin``, ``tmax``, ``fmin`` and ``fmax`` by `Mainak Jas`_

- Fix channel names in topomaps by `Alex Gramfort`_

- Fix mapping of ``l_trans_bandwidth`` (to low frequency) and ``h_trans_bandwidth`` (to high frequency) in ``_BaseRaw.filter`` by `Denis Engemann`_

- Fix scaling source spaces when distances have to be recomputed by `Christian Brodbeck`_

- Fix repeated samples in client to FieldTrip buffer by `Mainak Jas`_ and `Federico Raimondo`_

- Fix highpass and lowpass units read from Brainvision vhdr files by `Alex Gramfort`_

- Add missing attributes for BrainVision and KIT systems needed for resample by `Teon Brooks`_

- Fix file extensions of SSP projection files written by mne commands (from _proj.fif to -prof.fif) by `Alex Gramfort`_

- Generating EEG layouts no longer requires digitization points by `Marijn van Vliet`_

- Add missing attributes to BTI, KIT, and BrainVision by `Eric Larson`_

- The API change to the edf, brainvision, and egi break backwards compatibility for when importing eeg data by `Teon Brooks`_

- Fix bug in ``mne.viz.plot_topo`` if ylim was passed for single sensor layouts by `Denis Engemann`_

- Average reference projections will no longer by automatically added after applying a custom EEG reference by `Marijn van Vliet`_

- Fix picks argument to filter in n dimensions (affects FilterEstimator), and highpass filter in FilterEstimator by `Mainak Jas`_

- Fix beamformer code LCMV/DICS for CTF data with reference channels by `Denis Engemann`_ and `Alex Gramfort`_

- Fix scalings for bad EEG channels in ``mne.viz.plot_topo`` by `Marijn van Vliet`_

- Fix EGI reading when no events are present by `Federico Raimondo`_

- Add functionality to determine plot limits automatically or by data percentiles by `Mark Wronkiewicz`_

- Fix bug in mne.io.edf where the channel offsets were omitted in the voltage calculations by `Teon Brooks`_

- Decouple section ordering in command-line from python interface for mne-report by `Mainak Jas`_

- Fix bug with ICA resetting by `Denis Engemann`_

API
~~~

- apply_inverse functions have a new boolean parameter ``prepared`` which saves computation time by calling ``prepare_inverse_operator`` only if it is False

- find_events and read_events functions have a new parameter ``mask`` to set some bits to a don't care state by `Teon Brooks`_

- New channels module including layouts, electrode montages, and neighbor definitions of sensors which deprecates ``mne.layouts`` by `Denis Engemann`_

- ``read_raw_brainvision``, ``read_raw_edf``, ``read_raw_egi`` all use a standard montage import by `Teon Brooks`_

- Fix missing calibration factors for ``mne.io.egi.read_raw_egi`` by `Denis Engemann`_ and `Federico Raimondo`_

- Allow multiple filename patterns as a list (e.g., \*raw.fif and \*-eve.fif) to be parsed by mne report in ``Report.parse_folder()`` by `Mainak Jas`_

- ``read_hsp``, ``read_elp``, and ``write_hsp``, ``write_mrk`` were removed and made private by `Teon Brooks`_

- When computing the noise covariance or MNE inverse solutions, the rank is estimated empirically using more sensitive thresholds, which stabilizes results by `Denis Engemann`_ and `Eric Larson`_ and `Alex Gramfort`_

- Raw FIFF files can be preloaded after class instantiation using ``raw.preload_data()``

- Add ``label`` parameter to ``apply_inverse`` by `Teon Brooks`_

- Deprecated ``label_time_courses`` for ``in_label`` method in `SourceEstimate` by `Teon Brooks`_

- Deprecated ``as_data_frame`` for ``to_data_frame`` by `Chris Holdgraf`_

- Add ``transform``, ``unit`` parameters to ``read_montage`` by `Teon Brooks`_

- Deprecated ``fmin, fmid, fmax`` in stc.plot and added ``clim`` by `Mark Wronkiewicz`_

- Use ``scipy.signal.welch`` instead of matplotlib.psd inside ``compute_raw_psd`` and ``compute_epochs_psd`` by `Yousra Bekhti`_ `Eric Larson`_ and `Denis Engemann`_. As a consequence, ``Raw.plot_raw_psds`` has been deprecated.

- ``Raw`` instances returned by ``mne.forward.apply_forward_raw`` now always have times starting from
  zero to be consistent with all other ``Raw`` instances. To get the former ``start`` and ``stop`` times,
  use ``raw.first_samp / raw.info['sfreq']`` and ``raw.last_samp / raw.info['sfreq']``.

- ``pick_types_evoked`` has been deprecated in favor of ``evoked.pick_types``.

- Deprecated changing the sensor type of channels in ``rename_channels`` by `Teon Brooks`_

- CUDA is no longer initialized at module import, but only when first used.

- ``add_figs_to_section`` and ``add_images_to_section`` now have a ``textbox`` parameter to add comments to the image by `Teon Brooks`_

- Deprecated ``iir_filter_raw`` for ``fit_iir_model_raw``.

- Add ``montage`` parameter to the ``create_info`` function to create the info using montages by `Teon Brooks`_

Authors
~~~~~~~

The committer list for this release is the following (preceded by number of commits):

* 515  Eric Larson
* 343  Denis A. Engemann
* 304  Alexandre Gramfort
* 300  Teon Brooks
* 142  Mainak Jas
* 119  Jean-Remi King
*  77  Alan Leggitt
*  75  Marijn van Vliet
*  63  Chris Holdgraf
*  57  Yousra Bekhti
*  49  Mark Wronkiewicz
*  44  Christian Brodbeck
*  30  Jona Sassenhagen
*  29  Hari Bharadwaj
*  27  Clément Moutard
*  24  Ingoo Lee
*  18  Marmaduke Woodman
*  16  Martin Luessi
*  10  Jaakko Leppakangas
*   9  Andrew Dykstra
*   9  Daniel Strohmeier
*   7  kjs
*   6  Dan G. Wakeman
*   5  Federico Raimondo
*   3  Basile Pinsard
*   3  Christoph Dinh
*   3  Hafeza Anevar
*   2  Martin Billinger
*   2  Roan LaPlante
*   1  Manoj Kumar
*   1  Matt Tucker
*   1  Romain Trachel
*   1  mads jensen
*   1  sviter
